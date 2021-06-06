/**
 * @file addon.cc
 * @author Richard Nguyen (richardnguyen@github.com)
 * @brief Main addon file for Express
 * @version 0.1
 * @date 2021-05-26
 *
 * @copyright Copyright (c) 2021
 */

#include "Sorting.h"
// #include "Utility.h"
//#include "sorting.h"
#include "animation.h"
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

  std::vector<int> tempArr;
  Napi::Array arr = info[0].As<Napi::Array>();

  for (int i = 0; i < arr.Length(); i++)
  {
    tempArr.push_back(Napi::Value(arr[i]).ToNumber().Int32Value());
  }

  NSorting::bubble_sort(tempArr);

  Napi::Array returnArr = Napi::Array::New(info.Env(), tempArr.size());

  uint32_t i = 0;
  for (auto &e : tempArr)
  {
    returnArr[i++] = Napi::Number::New(info.Env(), e);
  }

  return returnArr;
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

Napi::Value InsertionSort(const Napi::CallbackInfo &info)
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

  for (int i = 0; i < arr.Length(); i++)
  {
    tempArr.push_back(Napi::Value(arr[i]).ToNumber().Int32Value());
  }

  NSorting::insertion_sort(tempArr);

  Napi::Array returnArr = Napi::Array::New(info.Env(), tempArr.size());

  uint32_t i = 0;
  for (auto &e : tempArr)
  {
    returnArr[i++] = Napi::Number::New(info.Env(), e);
  }

  return returnArr;
}

Napi::Value GetInsertionSortAnimation(const Napi::CallbackInfo &info)
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

  std::vector<std::vector<int>> animations;
  std::vector<int> tempArr;
  Napi::Array arr = info[0].As<Napi::Array>();

  for (int i = 0; i < arr.Length(); i++)
  {
    tempArr.push_back(Napi::Value(arr[i]).ToNumber().Int32Value());
  }

  animations = NSorting::get_insertion_sort_animation(tempArr);

  Napi::Array returnAnimations = Napi::Array::New(info.Env(), animations.size());

  uint32_t i = 0;
  for (auto &e : animations)
  {
    Napi::Array animation = Napi::Array::New(info.Env(), e.size());

    uint32_t ii = 0;
    for (auto &l : e)
    {
      animation[ii++] = Napi::Number::New(env, l);
    }

    returnAnimations[i++] = animation;
  }

  return returnAnimations;
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, Method));
  exports.Set(Napi::String::New(env, "randomIntegers"), Napi::Function::New(env, CreateRandomIntegers));
  exports.Set(Napi::String::New(env, "bubbleSort"), Napi::Function::New(env, BubbleSort));
  exports.Set(Napi::String::New(env, "insertionSort"), Napi::Function::New(env, InsertionSort));
  exports.Set(Napi::String::New(env, "getBubbleSortAnimation"), Napi::Function::New(env, GetBubbleSortAnimation));
  exports.Set(Napi::String::New(env, "getInsertionSortAnimation"), Napi::Function::New(env, GetInsertionSortAnimation));
  return exports;
}

NODE_API_MODULE(hello, Init);
