
#ifndef V8_SIMPLE_LOCALE_H_
#define V8_SIMPLE_LOCALE_H_

#include "src/builtins/builtins-utils.h"
#include "src/builtins/builtins.h"
#include "src/code-factory.h"
#include "src/code-stub-assembler.h"

namespace v8 {
namespace internal {

Object* LocaleNumberPrototypeToLocaleString(Isolate* isolate, BuiltinArguments& args, Handle<Object> value) {
  if (args.length() < 3)
    return *isolate->factory()->NumberToString(value);

  Handle<Object> locale = args.at<Object>(1);
  if (!locale->IsString())
    return *isolate->factory()->NumberToString(value);

  Handle<String> locale_string = args.at<String>(1);
  std::unique_ptr<char[]> locale_str = locale_string->ToCString();
  char* locale_str_ptr = locale_str.get();
  if (!locale_str_ptr)
    return *isolate->factory()->NumberToString(value);

  Handle<Object> opt = args.at<Object>(2);

  Vector<const char> style_buf("style", 5);
  MaybeHandle<String> style_buffer = isolate->factory()->NewStringFromUtf8(style_buf);

  Handle<Object> style_obj;
  Runtime::GetObjectProperty(isolate, opt, style_buffer.ToHandleChecked()).ToHandle(&style_obj);
  if (!(*style_obj))
    return *isolate->factory()->NumberToString(value);

  Handle<String> style_str = Object::ToString(isolate, style_obj).ToHandleChecked();
  std::unique_ptr<char[]> style_string = style_str->ToCString();
  char* style_string_ptr = style_string.get();
  if (!style_string_ptr)
    return *isolate->factory()->NumberToString(value);

  std::string style = style_string_ptr;
  std::transform(style.begin(), style.end(), style.begin(), ::tolower);

  if (style != "currency")
    return  *isolate->factory()->NumberToString(value);

  Vector<const char> currency_buf("currency", 8);
  Handle<String> currency_buffer = isolate->factory()->NewStringFromUtf8(currency_buf).ToHandleChecked();

  Handle<Object> currency_obj;
  Runtime::GetObjectProperty(isolate, opt, currency_buffer).ToHandle(&currency_obj);
  if (!(*currency_obj))
    return *isolate->factory()->NumberToString(value);

  MaybeHandle<String> currency_str = Object::ToString(isolate, currency_obj);
  Handle<String> currency_string = currency_str.ToHandleChecked();
  std::unique_ptr<char[]> currency_p = currency_string->ToCString();
  char* currency_ptr = currency_p.get();
  if (!currency_ptr)
    return *isolate->factory()->NumberToString(value);

  std::string currency = currency_ptr;
  std::transform(currency.begin(), currency.end(), currency.begin(), ::tolower);

  if (currency == "cny" || 
      currency == "usd" ||
      currency == "jpy" || 
      currency == "twd" || 
      currency == "eur" ||
      currency == "brl") {
    Handle<String> value_str = Object::ToString(isolate, isolate->factory()->NumberToString(value)).ToHandleChecked();
    std::string result_string = value_str->ToCString().get();

    if (currency == "cny")
      result_string = "CN\xEF\xBF\xA5" + result_string;
    else if (currency == "usd")
      result_string = "US$" + result_string;
    else if (currency == "jpy")
      result_string = "JP\xEF\xBF\xA5" + result_string;
    else if (currency == "twd")
      result_string = "nt$" + result_string;
    else if (currency == "eur")
      result_string = "\xE2\x82\xAC" + result_string;
    else if (currency == "brl")
      result_string = "R$" + result_string;

    Vector<const char> result_str(result_string.c_str(), result_string.size());
    MaybeHandle<String> result = isolate->factory()->NewStringFromUtf8(result_str);
    return *(result.ToHandleChecked());
  }

  return  *isolate->factory()->NumberToString(value);
}

}
}

#endif // V8_SIMPLE_LOCALE_H_