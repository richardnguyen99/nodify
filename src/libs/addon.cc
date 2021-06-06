/**
 * @file addon.cc
 * @author Richard Nguyen (richardnguyen@github.com)
 * @brief Main addon file for Express
 * @version 0.1
 * @date 2021-05-26
 *
 * @copyright Copyright (c) 2021
 */

// #include "Sorting.h"
// #include "Utility.h"
#include "animation.h"
#include "sorting.h"
#include "utility.h"
#include <iostream>
#include <napi.h>
#include <vector>

/**
 * @brief Ping function to test if this addon is working
 *
 * @param info
 * @return Napi::String
 */
Napi::String Method(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  return Napi::String::New(env, "world");
}

/**
 * @brief Create a Random Integers object
 *
 * @param info
 * @return Napi::Value
 */
Napi::Value CreateRandomIntegers(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  if (info.Length() < 1)
  {
    Napi::TypeError::New(env, "Require one argument in randomIntegers()").ThrowAsJavaScriptException();

    return env.Null();
  }

  if (!info[0].IsNumber())
  {
    Napi::TypeError::New(env, "Require an integer in randomIntegers()").ThrowAsJavaScriptException();

    return env.Null();
  }

  int listSize = info[0].As<Napi::Number>().Int32Value();
  auto random_arr = nodify::generate_data<int>(listSize);

  Napi::Array randomArray = nodify::ToJSArray(info, std::begin(random_arr), std::end(random_arr));

  return randomArray;
}

Napi::Value BubbleSort(const Napi::CallbackInfo &info)
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

  std::vector<int> native_array;
  Napi::Array jsInputArray = info[0].As<Napi::Array>();

  for (int i = 0; i < jsInputArray.Length(); i++)
  {
    native_array.push_back(Napi::Value(jsInputArray[i]).ToNumber().Int32Value());
  }

  nodify::bubble_sort(std::begin(native_array), std::end(native_array));

  Napi::Array jsReturnArr = nodify::ToJSArray(info, std::begin(native_array), std::end(native_array));

  return jsReturnArr;
}

/**
 * @brief Get the Bubble Sort Animation object
 *
 * @param info
 * @return Napi::Value
 */
Napi::Value GetBubbleSortAnimation(const Napi::CallbackInfo &info)
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

  nodify::Animation animation;
  std::vector<int> native_array;
  Napi::Array jsArray = info[0].As<Napi::Array>();

  for (int i = 0; i < jsArray.Length(); i++)
  {
    native_array.push_back(Napi::Value(jsArray[i]).ToNumber().Int32Value());
  }

  nodify::get_bubble_sort_animation(std::begin(native_array), std::end(native_array), animation);
  Napi::Array jsAnimation = Napi::Array::New(info.Env(), animation.sorting.size());

  for (auto current = std::begin(animation.sorting); current < std::end(animation.sorting); ++current)
  {
    Napi::Array jsStep = nodify::ToJSArray(info, std::begin(*current), std::end(*current));

    jsAnimation[static_cast<int>(std::distance(std::begin(animation.sorting), current))] = jsStep;
  }

  return jsAnimation;
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, Method));
  exports.Set(Napi::String::New(env, "randomIntegers"), Napi::Function::New(env, CreateRandomIntegers));
  exports.Set(Napi::String::New(env, "bubbleSort"), Napi::Function::New(env, BubbleSort));
  exports.Set(Napi::String::New(env, "getBubbleSortAnimation"), Napi::Function::New(env, GetBubbleSortAnimation));
  return exports;
}

NODE_API_MODULE(hello, Init);
