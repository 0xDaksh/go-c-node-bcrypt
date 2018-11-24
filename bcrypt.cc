#include <node.h>
#include "./bcrypt.h"

namespace bcrypt {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

const char* ToCString(const String::Utf8Value& value) {
  return *value ? *value : "<string conversion failed>";
}

void EncryptFn(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  String::Utf8Value str(args[0]);
  const char* cstr = ToCString(str);
  char * charstr = const_cast<char *>(cstr);
  char* result = Encrypt(charstr);
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, result));
}

void CompareFn(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  String::Utf8Value str(args[0]);
  String::Utf8Value str1(args[1]);

  const char* cstr = ToCString(str);
  char * charstr = const_cast<char *>(cstr);

  const char* cstr1 = ToCString(str1);
  char * charstr1 = const_cast<char *>(cstr1);


  char* result = Compare(charstr, charstr1);
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, result));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "encrypt", EncryptFn);
  NODE_SET_METHOD(exports, "compare", CompareFn);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace bcrypt