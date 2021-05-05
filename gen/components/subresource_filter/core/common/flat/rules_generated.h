// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_RULES_SUBRESOURCE_FILTER_FLAT_H_
#define FLATBUFFERS_GENERATED_RULES_SUBRESOURCE_FILTER_FLAT_H_

#include "flatbuffers/flatbuffers.h"

namespace subresource_filter {
namespace flat {

    struct UrlRule;

    struct NGramToRules;

    struct UrlPatternIndex;

    struct IndexedRuleset;

    enum UrlPatternType {
        UrlPatternType_SUBSTRING = 0,
        UrlPatternType_WILDCARDED = 1,
        UrlPatternType_REGEXP = 2,
        UrlPatternType_MIN = UrlPatternType_SUBSTRING,
        UrlPatternType_MAX = UrlPatternType_REGEXP
    };

    inline const char** EnumNamesUrlPatternType()
    {
        static const char* names[] = { "SUBSTRING", "WILDCARDED", "REGEXP", nullptr };
        return names;
    }

    inline const char* EnumNameUrlPatternType(UrlPatternType e) { return EnumNamesUrlPatternType()[static_cast<int>(e)]; }

    enum AnchorType {
        AnchorType_NONE = 0,
        AnchorType_BOUNDARY = 1,
        AnchorType_SUBDOMAIN = 2,
        AnchorType_MIN = AnchorType_NONE,
        AnchorType_MAX = AnchorType_SUBDOMAIN
    };

    inline const char** EnumNamesAnchorType()
    {
        static const char* names[] = { "NONE", "BOUNDARY", "SUBDOMAIN", nullptr };
        return names;
    }

    inline const char* EnumNameAnchorType(AnchorType e) { return EnumNamesAnchorType()[static_cast<int>(e)]; }

    enum OptionFlag {
        OptionFlag_IS_WHITELIST = 1,
        OptionFlag_APPLIES_TO_FIRST_PARTY = 2,
        OptionFlag_APPLIES_TO_THIRD_PARTY = 4,
        OptionFlag_IS_MATCH_CASE = 8,
        OptionFlag_NONE = 0,
        OptionFlag_ANY = 15
    };

    inline const char** EnumNamesOptionFlag()
    {
        static const char* names[] = { "IS_WHITELIST", "APPLIES_TO_FIRST_PARTY", "", "APPLIES_TO_THIRD_PARTY", "", "", "", "IS_MATCH_CASE", nullptr };
        return names;
    }

    inline const char* EnumNameOptionFlag(OptionFlag e) { return EnumNamesOptionFlag()[static_cast<int>(e) - static_cast<int>(OptionFlag_IS_WHITELIST)]; }

    struct UrlRule FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
        enum {
            VT_OPTIONS = 4,
            VT_ELEMENT_TYPES = 6,
            VT_ACTIVATION_TYPES = 8,
            VT_URL_PATTERN_TYPE = 10,
            VT_ANCHOR_LEFT = 12,
            VT_ANCHOR_RIGHT = 14,
            VT_DOMAINS = 16,
            VT_URL_PATTERN = 18,
            VT_FAILURE_FUNCTION = 20
        };
        uint8_t options() const { return GetField<uint8_t>(VT_OPTIONS, 0); }
        uint16_t element_types() const { return GetField<uint16_t>(VT_ELEMENT_TYPES, 2047); }
        uint8_t activation_types() const { return GetField<uint8_t>(VT_ACTIVATION_TYPES, 0); }
        UrlPatternType url_pattern_type() const { return static_cast<UrlPatternType>(GetField<uint8_t>(VT_URL_PATTERN_TYPE, 0)); }
        AnchorType anchor_left() const { return static_cast<AnchorType>(GetField<uint8_t>(VT_ANCHOR_LEFT, 0)); }
        AnchorType anchor_right() const { return static_cast<AnchorType>(GetField<uint8_t>(VT_ANCHOR_RIGHT, 0)); }
        const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>* domains() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>*>(VT_DOMAINS); }
        const flatbuffers::String* url_pattern() const { return GetPointer<const flatbuffers::String*>(VT_URL_PATTERN); }
        const flatbuffers::Vector<uint8_t>* failure_function() const { return GetPointer<const flatbuffers::Vector<uint8_t>*>(VT_FAILURE_FUNCTION); }
        bool Verify(flatbuffers::Verifier& verifier) const
        {
            return VerifyTableStart(verifier) && VerifyField<uint8_t>(verifier, VT_OPTIONS) && VerifyField<uint16_t>(verifier, VT_ELEMENT_TYPES) && VerifyField<uint8_t>(verifier, VT_ACTIVATION_TYPES) && VerifyField<uint8_t>(verifier, VT_URL_PATTERN_TYPE) && VerifyField<uint8_t>(verifier, VT_ANCHOR_LEFT) && VerifyField<uint8_t>(verifier, VT_ANCHOR_RIGHT) && VerifyField<flatbuffers::uoffset_t>(verifier, VT_DOMAINS) && verifier.Verify(domains()) && verifier.VerifyVectorOfStrings(domains()) && VerifyField<flatbuffers::uoffset_t>(verifier, VT_URL_PATTERN) && verifier.Verify(url_pattern()) && VerifyField<flatbuffers::uoffset_t>(verifier, VT_FAILURE_FUNCTION) && verifier.Verify(failure_function()) && verifier.EndTable();
        }
    };

    struct UrlRuleBuilder {
        flatbuffers::FlatBufferBuilder& fbb_;
        flatbuffers::uoffset_t start_;
        void add_options(uint8_t options) { fbb_.AddElement<uint8_t>(UrlRule::VT_OPTIONS, options, 0); }
        void add_element_types(uint16_t element_types) { fbb_.AddElement<uint16_t>(UrlRule::VT_ELEMENT_TYPES, element_types, 2047); }
        void add_activation_types(uint8_t activation_types) { fbb_.AddElement<uint8_t>(UrlRule::VT_ACTIVATION_TYPES, activation_types, 0); }
        void add_url_pattern_type(UrlPatternType url_pattern_type) { fbb_.AddElement<uint8_t>(UrlRule::VT_URL_PATTERN_TYPE, static_cast<uint8_t>(url_pattern_type), 0); }
        void add_anchor_left(AnchorType anchor_left) { fbb_.AddElement<uint8_t>(UrlRule::VT_ANCHOR_LEFT, static_cast<uint8_t>(anchor_left), 0); }
        void add_anchor_right(AnchorType anchor_right) { fbb_.AddElement<uint8_t>(UrlRule::VT_ANCHOR_RIGHT, static_cast<uint8_t>(anchor_right), 0); }
        void add_domains(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> domains) { fbb_.AddOffset(UrlRule::VT_DOMAINS, domains); }
        void add_url_pattern(flatbuffers::Offset<flatbuffers::String> url_pattern) { fbb_.AddOffset(UrlRule::VT_URL_PATTERN, url_pattern); }
        void add_failure_function(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> failure_function) { fbb_.AddOffset(UrlRule::VT_FAILURE_FUNCTION, failure_function); }
        UrlRuleBuilder(flatbuffers::FlatBufferBuilder& _fbb)
            : fbb_(_fbb)
        {
            start_ = fbb_.StartTable();
        }
        UrlRuleBuilder& operator=(const UrlRuleBuilder&);
        flatbuffers::Offset<UrlRule> Finish()
        {
            auto o = flatbuffers::Offset<UrlRule>(fbb_.EndTable(start_, 9));
            return o;
        }
    };

    inline flatbuffers::Offset<UrlRule> CreateUrlRule(flatbuffers::FlatBufferBuilder& _fbb,
        uint8_t options = 0,
        uint16_t element_types = 2047,
        uint8_t activation_types = 0,
        UrlPatternType url_pattern_type = UrlPatternType_SUBSTRING,
        AnchorType anchor_left = AnchorType_NONE,
        AnchorType anchor_right = AnchorType_NONE,
        flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> domains = 0,
        flatbuffers::Offset<flatbuffers::String> url_pattern = 0,
        flatbuffers::Offset<flatbuffers::Vector<uint8_t>> failure_function = 0)
    {
        UrlRuleBuilder builder_(_fbb);
        builder_.add_failure_function(failure_function);
        builder_.add_url_pattern(url_pattern);
        builder_.add_domains(domains);
        builder_.add_element_types(element_types);
        builder_.add_anchor_right(anchor_right);
        builder_.add_anchor_left(anchor_left);
        builder_.add_url_pattern_type(url_pattern_type);
        builder_.add_activation_types(activation_types);
        builder_.add_options(options);
        return builder_.Finish();
    }

    struct NGramToRules FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
        enum {
            VT_NGRAM = 4,
            VT_RULE_LIST = 6
        };
        uint64_t ngram() const { return GetField<uint64_t>(VT_NGRAM, 0); }
        const flatbuffers::Vector<flatbuffers::Offset<UrlRule>>* rule_list() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<UrlRule>>*>(VT_RULE_LIST); }
        bool Verify(flatbuffers::Verifier& verifier) const
        {
            return VerifyTableStart(verifier) && VerifyField<uint64_t>(verifier, VT_NGRAM) && VerifyField<flatbuffers::uoffset_t>(verifier, VT_RULE_LIST) && verifier.Verify(rule_list()) && verifier.VerifyVectorOfTables(rule_list()) && verifier.EndTable();
        }
    };

    struct NGramToRulesBuilder {
        flatbuffers::FlatBufferBuilder& fbb_;
        flatbuffers::uoffset_t start_;
        void add_ngram(uint64_t ngram) { fbb_.AddElement<uint64_t>(NGramToRules::VT_NGRAM, ngram, 0); }
        void add_rule_list(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<UrlRule>>> rule_list) { fbb_.AddOffset(NGramToRules::VT_RULE_LIST, rule_list); }
        NGramToRulesBuilder(flatbuffers::FlatBufferBuilder& _fbb)
            : fbb_(_fbb)
        {
            start_ = fbb_.StartTable();
        }
        NGramToRulesBuilder& operator=(const NGramToRulesBuilder&);
        flatbuffers::Offset<NGramToRules> Finish()
        {
            auto o = flatbuffers::Offset<NGramToRules>(fbb_.EndTable(start_, 2));
            return o;
        }
    };

    inline flatbuffers::Offset<NGramToRules> CreateNGramToRules(flatbuffers::FlatBufferBuilder& _fbb,
        uint64_t ngram = 0,
        flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<UrlRule>>> rule_list = 0)
    {
        NGramToRulesBuilder builder_(_fbb);
        builder_.add_ngram(ngram);
        builder_.add_rule_list(rule_list);
        return builder_.Finish();
    }

    struct UrlPatternIndex FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
        enum {
            VT_N = 4,
            VT_NGRAM_INDEX = 6,
            VT_NGRAM_INDEX_EMPTY_SLOT = 8,
            VT_FALLBACK_RULES = 10
        };
        uint32_t n() const { return GetField<uint32_t>(VT_N, 0); }
        const flatbuffers::Vector<flatbuffers::Offset<NGramToRules>>* ngram_index() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<NGramToRules>>*>(VT_NGRAM_INDEX); }
        const NGramToRules* ngram_index_empty_slot() const { return GetPointer<const NGramToRules*>(VT_NGRAM_INDEX_EMPTY_SLOT); }
        const flatbuffers::Vector<flatbuffers::Offset<UrlRule>>* fallback_rules() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<UrlRule>>*>(VT_FALLBACK_RULES); }
        bool Verify(flatbuffers::Verifier& verifier) const
        {
            return VerifyTableStart(verifier) && VerifyField<uint32_t>(verifier, VT_N) && VerifyField<flatbuffers::uoffset_t>(verifier, VT_NGRAM_INDEX) && verifier.Verify(ngram_index()) && verifier.VerifyVectorOfTables(ngram_index()) && VerifyField<flatbuffers::uoffset_t>(verifier, VT_NGRAM_INDEX_EMPTY_SLOT) && verifier.VerifyTable(ngram_index_empty_slot()) && VerifyField<flatbuffers::uoffset_t>(verifier, VT_FALLBACK_RULES) && verifier.Verify(fallback_rules()) && verifier.VerifyVectorOfTables(fallback_rules()) && verifier.EndTable();
        }
    };

    struct UrlPatternIndexBuilder {
        flatbuffers::FlatBufferBuilder& fbb_;
        flatbuffers::uoffset_t start_;
        void add_n(uint32_t n) { fbb_.AddElement<uint32_t>(UrlPatternIndex::VT_N, n, 0); }
        void add_ngram_index(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<NGramToRules>>> ngram_index) { fbb_.AddOffset(UrlPatternIndex::VT_NGRAM_INDEX, ngram_index); }
        void add_ngram_index_empty_slot(flatbuffers::Offset<NGramToRules> ngram_index_empty_slot) { fbb_.AddOffset(UrlPatternIndex::VT_NGRAM_INDEX_EMPTY_SLOT, ngram_index_empty_slot); }
        void add_fallback_rules(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<UrlRule>>> fallback_rules) { fbb_.AddOffset(UrlPatternIndex::VT_FALLBACK_RULES, fallback_rules); }
        UrlPatternIndexBuilder(flatbuffers::FlatBufferBuilder& _fbb)
            : fbb_(_fbb)
        {
            start_ = fbb_.StartTable();
        }
        UrlPatternIndexBuilder& operator=(const UrlPatternIndexBuilder&);
        flatbuffers::Offset<UrlPatternIndex> Finish()
        {
            auto o = flatbuffers::Offset<UrlPatternIndex>(fbb_.EndTable(start_, 4));
            return o;
        }
    };

    inline flatbuffers::Offset<UrlPatternIndex> CreateUrlPatternIndex(flatbuffers::FlatBufferBuilder& _fbb,
        uint32_t n = 0,
        flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<NGramToRules>>> ngram_index = 0,
        flatbuffers::Offset<NGramToRules> ngram_index_empty_slot = 0,
        flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<UrlRule>>> fallback_rules = 0)
    {
        UrlPatternIndexBuilder builder_(_fbb);
        builder_.add_fallback_rules(fallback_rules);
        builder_.add_ngram_index_empty_slot(ngram_index_empty_slot);
        builder_.add_ngram_index(ngram_index);
        builder_.add_n(n);
        return builder_.Finish();
    }

    struct IndexedRuleset FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
        enum {
            VT_BLACKLIST_INDEX = 4,
            VT_WHITELIST_INDEX = 6
        };
        const UrlPatternIndex* blacklist_index() const { return GetPointer<const UrlPatternIndex*>(VT_BLACKLIST_INDEX); }
        const UrlPatternIndex* whitelist_index() const { return GetPointer<const UrlPatternIndex*>(VT_WHITELIST_INDEX); }
        bool Verify(flatbuffers::Verifier& verifier) const
        {
            return VerifyTableStart(verifier) && VerifyField<flatbuffers::uoffset_t>(verifier, VT_BLACKLIST_INDEX) && verifier.VerifyTable(blacklist_index()) && VerifyField<flatbuffers::uoffset_t>(verifier, VT_WHITELIST_INDEX) && verifier.VerifyTable(whitelist_index()) && verifier.EndTable();
        }
    };

    struct IndexedRulesetBuilder {
        flatbuffers::FlatBufferBuilder& fbb_;
        flatbuffers::uoffset_t start_;
        void add_blacklist_index(flatbuffers::Offset<UrlPatternIndex> blacklist_index) { fbb_.AddOffset(IndexedRuleset::VT_BLACKLIST_INDEX, blacklist_index); }
        void add_whitelist_index(flatbuffers::Offset<UrlPatternIndex> whitelist_index) { fbb_.AddOffset(IndexedRuleset::VT_WHITELIST_INDEX, whitelist_index); }
        IndexedRulesetBuilder(flatbuffers::FlatBufferBuilder& _fbb)
            : fbb_(_fbb)
        {
            start_ = fbb_.StartTable();
        }
        IndexedRulesetBuilder& operator=(const IndexedRulesetBuilder&);
        flatbuffers::Offset<IndexedRuleset> Finish()
        {
            auto o = flatbuffers::Offset<IndexedRuleset>(fbb_.EndTable(start_, 2));
            return o;
        }
    };

    inline flatbuffers::Offset<IndexedRuleset> CreateIndexedRuleset(flatbuffers::FlatBufferBuilder& _fbb,
        flatbuffers::Offset<UrlPatternIndex> blacklist_index = 0,
        flatbuffers::Offset<UrlPatternIndex> whitelist_index = 0)
    {
        IndexedRulesetBuilder builder_(_fbb);
        builder_.add_whitelist_index(whitelist_index);
        builder_.add_blacklist_index(blacklist_index);
        return builder_.Finish();
    }

    inline const subresource_filter::flat::IndexedRuleset* GetIndexedRuleset(const void* buf) { return flatbuffers::GetRoot<subresource_filter::flat::IndexedRuleset>(buf); }

    inline bool VerifyIndexedRulesetBuffer(flatbuffers::Verifier& verifier) { return verifier.VerifyBuffer<subresource_filter::flat::IndexedRuleset>(); }

    inline void FinishIndexedRulesetBuffer(flatbuffers::FlatBufferBuilder& fbb, flatbuffers::Offset<subresource_filter::flat::IndexedRuleset> root) { fbb.Finish(root); }

} // namespace flat
} // namespace subresource_filter

#endif // FLATBUFFERS_GENERATED_RULES_SUBRESOURCE_FILTER_FLAT_H_
