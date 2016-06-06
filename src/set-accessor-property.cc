
#include <node.h>
#include <v8.h>

namespace module {

using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::Value;
using v8::String;

void Ctor(const FunctionCallbackInfo<Value>& args) {
  auto i = args.GetIsolate();
  if (not args.IsConstructCall()) {
    i->ThrowException(v8::Exception::Error(String::NewFromUtf8(i, "Must be called as constructor")));
    return;
  }
  args.GetReturnValue().Set(args.This());
}

void MethodA(const FunctionCallbackInfo<Value>& args) {
  args.GetReturnValue().Set(args[0]);
}

void MethodB(const FunctionCallbackInfo<Value>& args) {
  auto isolate = args.GetIsolate();
  auto fn = FunctionTemplate::New(
    isolate,
    [](const FunctionCallbackInfo<Value>& args) {
      args.GetReturnValue().Set(args[0]);
    }
  )->GetFunction();
  args.GetReturnValue().Set(fn);
}

void init(Local<Object> exports) {
  auto isolate = Isolate::GetCurrent();

  Local<FunctionTemplate> ctor = FunctionTemplate::New(isolate, Ctor);
  auto prototype = ctor->PrototypeTemplate();

  prototype->SetAccessorProperty(String::NewFromUtf8(isolate, "a"), FunctionTemplate::New(isolate, MethodA));
  prototype->SetAccessorProperty(String::NewFromUtf8(isolate, "b"), FunctionTemplate::New(isolate, MethodB));

  exports->Set(String::NewFromUtf8(isolate, "ctor"), ctor->GetFunction());
}

}

NODE_MODULE(setaccessorproperty, module::init)
