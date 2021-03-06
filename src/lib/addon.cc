#include <iostream>
#include <vector>
#include <napi.h>
#include "Sorting.h"
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

Napi::Value BubbleSort(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();

  if (info.Length() < 1)
  {
    Napi::TypeError::New(env, "require at least one argument").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsArray())
  {
    Napi::TypeError::New(env, "require argument as an array").ThrowAsJavaScriptException();
  return env.Null();
  }

  std::vector<int> tempArr;
  Napi::Array arr = info[0].As<Napi::Array>();

  for (int i = 0 ; i < arr.Length(); i++)
  {
    tempArr.push_back(Napi::Value(arr[i]).ToNumber().Int32Value());
  }

  NSorting::bubble_sort(tempArr);

  Napi::Array returnArr = Napi::Array::New(info.Env(), tempArr.size());

  uint32_t i = 0;
  for (auto& e : tempArr)
  {
    returnArr[i++] = Napi::Number::New(info.Env(), e);
  }

  return returnArr;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "hello"),
              Napi::Function::New(env, Method));
  exports.Set(Napi::String::New(env, "randomIntegers"), Napi::Function::New(env, CreateRandomIntegers));
  exports.Set(Napi::String::New(env, "bubbleSort"), Napi::Function::New(env, BubbleSort));
  return exports;
}

NODE_API_MODULE(hello, Init);
