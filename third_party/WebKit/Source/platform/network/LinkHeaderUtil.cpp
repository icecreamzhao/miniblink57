// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "LinkHeaderUtil.h"
#include "base/strings/string_tokenizer.h"
#include "base/strings/string_piece.h"
#include "base/strings/string_util.h"

// This is a macro to support extending this string literal at compile time.
// Please excuse me polluting your global namespace!
#define HTTP_LWS " \t"

namespace blink {

bool IsTokenChar(char c);

// See RFC 5987 Sec 3.2.1 for the definition of |parmname|.
bool IsParmName(std::string::const_iterator begin, std::string::const_iterator end)
{
    if (begin == end)
        return false;
    for (std::string::const_iterator iter = begin; iter != end; ++iter) {
        unsigned char c = *iter;
        if (!IsTokenChar(c) || c == '*' || c == '\'' || c == '%')
            return false;
    }
    return true;
}

bool IsQuote(char c)
{
    return c == '"';
}

bool UnquoteImpl(std::string::const_iterator begin, std::string::const_iterator end, bool strict_quotes, std::string* out)
{
    // Empty string
    if (begin == end)
        return false;

    // Nothing to unquote.
    if (!IsQuote(*begin))
        return false;

    // No terminal quote mark.
    if (end - begin < 2 || *begin != *(end - 1))
        return false;

    // Strip quotemarks
    ++begin;
    --end;

    // Unescape quoted-pair (defined in RFC 2616 section 2.2)
    bool prev_escape = false;
    std::string unescaped;
    for (; begin != end; ++begin) {
        char c = *begin;
        if (c == '\\' && !prev_escape) {
            prev_escape = true;
            continue;
        }
        if (strict_quotes && !prev_escape && IsQuote(c))
            return false;
        prev_escape = false;
        unescaped.push_back(c);
    }

    // Terminal quote is escaped.
    if (strict_quotes && prev_escape)
        return false;

    *out = std::move(unescaped);
    return true;
}

// static
bool StrictUnquote(std::string::const_iterator begin, std::string::const_iterator end, std::string* out)
{
    return UnquoteImpl(begin, end, true, out);
}

std::string Unquote(std::string::const_iterator begin, std::string::const_iterator end)
{
    std::string result;
    if (!UnquoteImpl(begin, end, false, &result))
        return std::string(begin, end);

    return result;
}

bool IsLWS(char c)
{
    const std::string kWhiteSpaceCharacters(HTTP_LWS);
    return kWhiteSpaceCharacters.find(c) != std::string::npos;
}

template <typename ConstIterator>
void TrimLWSImplementation(ConstIterator* begin, ConstIterator* end)
{
    // leading whitespace
    while (*begin < *end && IsLWS((*begin)[0]))
        ++(*begin);

    // trailing whitespace
    while (*begin < *end && IsLWS((*end)[-1]))
        --(*end);
}

// static
void TrimLWS(std::string::const_iterator* begin, std::string::const_iterator* end)
{
    TrimLWSImplementation(begin, end);
}

class ValuesIterator {
public:
    ValuesIterator(std::string::const_iterator values_begin,
        std::string::const_iterator values_end,
        char delimiter,
        bool ignore_empty_values = true);
    ValuesIterator(const ValuesIterator& other);
    ~ValuesIterator();

    // Advances the iterator to the next value, if any.  Returns true if there
    // is a next value.  Use value* methods to access the resultant value.
    bool GetNext();

    std::string::const_iterator value_begin() const
    {
        return value_begin_;
    }
    std::string::const_iterator value_end() const
    {
        return value_end_;
    }
    std::string value() const
    {
        return std::string(value_begin_, value_end_);
    }

private:
    base::StringTokenizer values_;
    std::string::const_iterator value_begin_;
    std::string::const_iterator value_end_;
    bool ignore_empty_values_;
};

ValuesIterator::ValuesIterator(
    std::string::const_iterator values_begin,
    std::string::const_iterator values_end,
    char delimiter,
    bool ignore_empty_values)
    : values_(values_begin, values_end, std::string(1, delimiter))
    , ignore_empty_values_(ignore_empty_values)
{
    values_.set_quote_chars("\"");
    // Could set this unconditionally, since code below has to check for empty
    // values after trimming, anyways, but may provide a minor performance
    // improvement.
    if (!ignore_empty_values_)
        values_.set_options(base::StringTokenizer::RETURN_EMPTY_TOKENS);
}

ValuesIterator::ValuesIterator(const ValuesIterator& other) = default;

ValuesIterator::~ValuesIterator() = default;

bool ValuesIterator::GetNext()
{
    while (values_.GetNext()) {
        value_begin_ = values_.token_begin();
        value_end_ = values_.token_end();
        TrimLWS(&value_begin_, &value_end_);

        if (!ignore_empty_values_ || value_begin_ != value_end_)
            return true;
    }
    return false;
}

class NameValuePairsIterator {
public:
    // Whether or not values are optional. Values::NOT_REQUIRED allows
    // e.g. name1=value1;name2;name3=value3, whereas Vaues::REQUIRED
    // will treat it as a parse error because name2 does not have a
    // corresponding equals sign.
    enum class Values { NOT_REQUIRED, REQUIRED };

    // Whether or not unmatched quotes should be considered a failure. By
    // default this class is pretty lenient and does a best effort to parse
    // values with mismatched quotes. When set to STRICT_QUOTES a value with
    // mismatched or otherwise invalid quotes is considered a parse error.
    enum class Quotes { STRICT_QUOTES, NOT_STRICT };

    NameValuePairsIterator(std::string::const_iterator begin, std::string::const_iterator end, char delimiter, Values optional_values, Quotes strict_quotes);

    // Treats values as not optional by default (Values::REQUIRED) and
    // treats quotes as not strict.
    NameValuePairsIterator(std::string::const_iterator begin, std::string::const_iterator end, char delimiter);

    NameValuePairsIterator(const NameValuePairsIterator& other);

    ~NameValuePairsIterator();

    // Advances the iterator to the next pair, if any.  Returns true if there
    // is a next pair.  Use name* and value* methods to access the resultant
    // value.
    bool GetNext();

    // Returns false if there was a parse error.
    bool valid() const { return valid_; }

    // The name of the current name-value pair.
    std::string::const_iterator name_begin() const { return name_begin_; }
    std::string::const_iterator name_end() const { return name_end_; }
    std::string name() const { return std::string(name_begin_, name_end_); }

    // The value of the current name-value pair.
    std::string::const_iterator value_begin() const
    {
        return value_is_quoted_ ? unquoted_value_.begin() : value_begin_;
    }

    std::string::const_iterator value_end() const
    {
        return value_is_quoted_ ? unquoted_value_.end() : value_end_;
    }

    std::string value() const
    {
        return value_is_quoted_ ? unquoted_value_ : std::string(value_begin_, value_end_);
    }

    bool value_is_quoted() const { return value_is_quoted_; }

    // The value before unquoting (if any).
    std::string raw_value() const
    {
        return std::string(value_begin_, value_end_);
    }

private:
    ValuesIterator props_;
    bool valid_;

    std::string::const_iterator name_begin_;
    std::string::const_iterator name_end_;

    std::string::const_iterator value_begin_;
    std::string::const_iterator value_end_;

    // Do not store iterators into this string. The NameValuePairsIterator
    // is copyable/assignable, and if copied the copy's iterators would point
    // into the original's unquoted_value_ member.
    std::string unquoted_value_;

    bool value_is_quoted_;

    // True if values are required for each name/value pair; false if a
    // name is permitted to appear without a corresponding value.
    bool values_optional_;

    // True if quotes values are required to be properly quoted; false if
    // mismatched quotes and other problems with quoted values should be more
    // or less gracefully treated as valid.
    bool strict_quotes_;
};

NameValuePairsIterator::NameValuePairsIterator(
    std::string::const_iterator begin,
    std::string::const_iterator end,
    char delimiter,
    Values optional_values,
    Quotes strict_quotes)
    : props_(begin, end, delimiter)
    , valid_(true)
    , name_begin_(end)
    , name_end_(end)
    , value_begin_(end)
    , value_end_(end)
    , value_is_quoted_(false)
    , values_optional_(optional_values == Values::NOT_REQUIRED)
    , strict_quotes_(strict_quotes == Quotes::STRICT_QUOTES)
{
}

NameValuePairsIterator::NameValuePairsIterator(std::string::const_iterator begin, std::string::const_iterator end, char delimiter)
    : NameValuePairsIterator(begin, end, delimiter, Values::REQUIRED, Quotes::NOT_STRICT)
{
}

NameValuePairsIterator::NameValuePairsIterator(const NameValuePairsIterator& other) = default;

NameValuePairsIterator::~NameValuePairsIterator() = default;

// We expect properties to be formatted as one of:
//   name="value"
//   name='value'
//   name='\'value\''
//   name=value
//   name = value
//   name (if values_optional_ is true)
// Due to buggy implementations found in some embedded devices, we also
// accept values with missing close quotemark (http://crbug.com/39836):
//   name="value
bool NameValuePairsIterator::GetNext()
{
    if (!props_.GetNext())
        return false;

    // Set the value as everything. Next we will split out the name.
    value_begin_ = props_.value_begin();
    value_end_ = props_.value_end();
    name_begin_ = name_end_ = value_end_;

    // Scan for the equals sign.
    std::string::const_iterator equals = std::find(value_begin_, value_end_, '=');
    if (equals == value_begin_)
        return valid_ = false;  // Malformed, no name
    if (equals == value_end_ && !values_optional_)
        return valid_ = false;  // Malformed, no equals sign and values are required

    // If an equals sign was found, verify that it wasn't inside of quote marks.
    if (equals != value_end_) {
        for (std::string::const_iterator it = value_begin_; it != equals; ++it) {
            if (IsQuote(*it))
                return valid_ = false;  // Malformed, quote appears before equals sign
        }
    }

    name_begin_ = value_begin_;
    name_end_ = equals;
    value_begin_ = (equals == value_end_) ? value_end_ : equals + 1;

    TrimLWS(&name_begin_, &name_end_);
    TrimLWS(&value_begin_, &value_end_);
    value_is_quoted_ = false;
    unquoted_value_.clear();

    if (equals != value_end_ && value_begin_ == value_end_) {
        // Malformed; value is empty
        return valid_ = false;
    }

    if (value_begin_ != value_end_ && IsQuote(*value_begin_)) {
        value_is_quoted_ = true;

        if (strict_quotes_) {
            if (!StrictUnquote(value_begin_, value_end_, &unquoted_value_))
                return valid_ = false;
            return true;
        }

        // Trim surrounding quotemarks off the value
        if (*value_begin_ != *(value_end_ - 1) || value_begin_ + 1 == value_end_) {
            // NOTE: This is not as graceful as it sounds:
            // * quoted-pairs will no longer be unquoted
            //   (["\"hello] should give ["hello]).
            // * Does not detect when the final quote is escaped
            //   (["value\"] should give [value"])
            value_is_quoted_ = false;
            ++value_begin_;  // Gracefully recover from mismatching quotes.
        } else {
            // Do not store iterators into this. See declaration of unquoted_value_.
            unquoted_value_ = Unquote(value_begin_, value_end_);
        }
    }

    return true;
}


namespace {

// A variation of base::StringTokenizer and net::ValuesIterator.
// Takes the parsing of StringTokenizer and adds support for quoted strings that
// are quoted by matching <> (and does not support escaping in those strings).
// Also has the behavior of ValuesIterator where it strips whitespace from all
// values and only outputs non-empty values.
// Only supports ',' as separator and supports "" and <> as quote chars.
class ValueTokenizer {
public:
    ValueTokenizer(std::string::const_iterator begin, std::string::const_iterator end)
        : token_begin_(begin), token_end_(begin), end_(end)
    {
    }

    std::string::const_iterator token_begin() const { return token_begin_; }
    std::string::const_iterator token_end() const { return token_end_; }

    bool GetNext()
    {
        while (GetNextInternal()) {
            TrimLWS(&token_begin_, &token_end_);

            // Only return non-empty values.
            if (token_begin_ != token_end_)
                return true;
        }
        return false;
    }

private:
    // Updates token_begin_ and token_end_ to point to the (possibly empty) next
    // token. Returns false if end-of-string was reached first.
    bool GetNextInternal()
    {
        // First time this is called token_end_ points to the first character in the
        // input. Every other time token_end_ points to the delimiter at the end of
        // the last returned token (which could be the end of the string).

        // End of string, return false.
        if (token_end_ == end_)
            return false;

        // Skip past the delimiter.
        if (*token_end_ == ',')
            ++token_end_;

        // Make token_begin_ point to the beginning of the next token, and search
        // for the end of the token in token_end_.
        token_begin_ = token_end_;

        // Set to true if we're currently inside a quoted string.
        bool in_quote = false;
        // Set to true if we're currently inside a quoted string, and have just
        // encountered an escape character. In this case a closing quote will be
        // ignored.
        bool in_escape = false;
        // If currently in a quoted string, this is the character that (when not
        // escaped) indicates the end of the string.
        char quote_close_char = '\0';
        // If currently in a quoted string, this is set to true if it is possible to
        // escape the closing quote using '\'.
        bool quote_allows_escape = false;

        while (token_end_ != end_) {
            char c = *token_end_;
            if (in_quote) {
                if (in_escape) {
                    in_escape = false;
                } else if (quote_allows_escape && c == '\\') {
                    in_escape = true;
                } else if (c == quote_close_char) {
                    in_quote = false;
                }
            } else {
                if (c == ',')
                    break;
                if (c == '"' || c == '<') {
                    in_quote = true;
                    quote_close_char = (c == '<' ? '>' : c);
                    quote_allows_escape = (c != '<');
                }
            }
            ++token_end_;
        }
        return true;
    }

    std::string::const_iterator token_begin_;
    std::string::const_iterator token_end_;
    std::string::const_iterator end_;
};

// Parses the URL part of a Link header. When successful |url_begin| points
// to the beginning of the url, |url_end| points to the end of the url and
// |params_begin| points to the first character after the '>' character at the
// end of the url.
bool ExtractURL(std::string::const_iterator begin,
    std::string::const_iterator end,
    std::string::const_iterator* url_begin,
    std::string::const_iterator* url_end,
    std::string::const_iterator* params_begin)
{
    // Extract the URL part (everything between '<' and first '>' character).
    if (*begin != '<')
        return false;

    ++begin;
    *url_begin = begin;
    *url_end = std::find(begin, end, '>');

    // Fail if we did not find a '>'.
    if (*url_end == end)
        return false;

    *params_begin = *url_end;
    // Skip the '>' at the end of the URL.
    ++* params_begin;

    // Trim whitespace from the URL.
    TrimLWS(url_begin, url_end);
    return true;
}

}  // namespace

std::vector<StringIteratorPair> SplitLinkHeader(const std::string& header)
{
    std::vector<StringIteratorPair> values;
    ValueTokenizer tokenizer(header.begin(), header.end());

    while (tokenizer.GetNext()) {
        values.push_back(StringIteratorPair(tokenizer.token_begin(), tokenizer.token_end()));
    }
    return values;
}

// Parses one link in a link header into its url and parameters.
// A link is of the form "<some-url>; param1=value1; param2=value2".
// Returns false if parsing the link failed, returns true on success. This
// method is more lenient than the RFC. It doesn't fail on things like invalid
// characters in the URL, and also doesn't verify that certain parameters should
// or shouldn't be quoted strings.
// If a parameter occurs more than once in the link, only the first value is
// returned in params as this is the required behavior for all attributes chrome
// currently cares about in link headers.
bool ParseLinkHeaderValue(
    std::string::const_iterator begin,
    std::string::const_iterator end,
    std::string* url,
    std::map<std::string, std::string>* params)
{
    // Can't parse an empty string.
    if (begin == end)
        return false;

    // Extract the URL part (everything between '<' and first '>' character).
    std::string::const_iterator url_begin;
    std::string::const_iterator url_end;
    if (!ExtractURL(begin, end, &url_begin, &url_end, &begin))
        return false;
    *url = std::string(url_begin, url_end);

    // Trim any remaining whitespace, and make sure there is a ';' separating
    // parameters from the URL.
    TrimLWS(&begin, &end);
    if (begin != end && *begin != ';')
        return false;

    // Parse all the parameters.
    NameValuePairsIterator params_iterator(begin, end, ';', NameValuePairsIterator::Values::NOT_REQUIRED, NameValuePairsIterator::Quotes::STRICT_QUOTES);
    while (params_iterator.GetNext()) {
        if (!IsParmName(params_iterator.name_begin(),
            params_iterator.name_end()))
            return false;

        std::string name = base::ToLowerASCII(base::StringPiece(params_iterator.name_begin(), params_iterator.name_end()));
        if (!params_iterator.value_is_quoted() && params_iterator.value_begin() == params_iterator.value_end())
            params->insert(std::make_pair(name, ""));
        else
            params->insert(std::make_pair(name, params_iterator.value()));
    }
    return params_iterator.valid();
}

}  // namespace link_header_util
