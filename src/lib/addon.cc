#include <iostream>
#include <napi.h>
#include "Utility.h"

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, "world");
}

Napi::Value CreateRandomIntegers(const Napi::CallbackInfo& info)
{
  auto random_arr = randomIntegers();

  Napi::Array random_array = Napi::Array::New(info.Env(), random_arr.size());

  uint32_t i = 0;
  for (auto& e : random_arr)
  {
    random_array[i++] = Napi::Number::New(info.Env(), e);
  }

  return random_array;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "hello"),
              Napi::Function::New(env, Method));
  exports.Set(Napi::String::New(env, "randomIntegers"), Napi::Function::New(env, CreateRandomIntegers));
  return exports;
}

NODE_API_MODULE(hello, Init);
