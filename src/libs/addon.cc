/**
 * @file addon.cc
 * @author Richard Nguyen (richardnguyen@github.com)
 * @brief Main addon file for Express
 * @version 0.1
 * @date 2021-05-26
 *
 * @copyright Copyright (c) 2021
 */

#include <napi.h>
#include <iostream>
#include <vector>
#include "Sorting.h"
#include "Utility.h"

Napi::String Method(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();
  return Napi::String::New(env, "world");
}

Napi::Value CreateRandomIntegers(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Require one argument in randomIntegers()")
        .ThrowAsJavaScriptException();

    return env.Null();
  }

  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Require an integer in randomIntegers()")
        .ThrowAsJavaScriptException();

    return env.Null();
  }

  int listSize = info[0].As<Napi::Number>().Int32Value();
  auto random_arr = Utility::generate_data<int>(listSize);

  Napi::Array random_array = Napi::Array::New(info.Env(), random_arr.size());

  uint32_t i = 0;
  for (auto& e : random_arr) {
    random_array[i++] = Napi::Number::New(info.Env(), e);
  }

  return random_array;
}

Napi::Value BubbleSort(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "require at least one argument")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsArray()) {
    Napi::TypeError::New(env, "require argument as an array")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  std::vector<int> tempArr;
  Napi::Array arr = info[0].As<Napi::Array>();

  for (int i = 0; i < arr.Length(); i++) {
    tempArr.push_back(Napi::Value(arr[i]).ToNumber().Int32Value());
  }

  NSorting::bubble_sort(tempArr);

  Napi::Array returnArr = Napi::Array::New(info.Env(), tempArr.size());

  uint32_t i = 0;
  for (auto& e : tempArr) {
    returnArr[i++] = Napi::Number::New(info.Env(), e);
  }

  return returnArr;
}

Napi::Value GetBubbleSortAnimation(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "require at least one argument")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsArray()) {
    Napi::TypeError::New(env, "require argument as an array")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  std::vector<std::vector<int>> animations;
  std::vector<int> tempArr;
  Napi::Array arr = info[0].As<Napi::Array>();

  for (int i = 0; i < arr.Length(); i++) {
    tempArr.push_back(Napi::Value(arr[i]).ToNumber().Int32Value());
  }

  animations = NSorting::get_bubble_sort_animation(tempArr);

  Napi::Array returnAnimations =
      Napi::Array::New(info.Env(), animations.size());

  uint32_t i = 0;
  for (auto& e : animations) {
    Napi::Array animation = Napi::Array::New(info.Env(), e.size());

    uint32_t ii = 0;
    for (auto& l : e) {
      animation[ii++] = Napi::Number::New(env, l);
    }

    returnAnimations[i++] = animation;
  }

  return returnAnimations;
}

Napi::Value InsertionSort(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "require at least one argument")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsArray()) {
    Napi::TypeError::New(env, "require argument as an array")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  std::vector<int> tempArr;
  Napi::Array arr = info[0].As<Napi::Array>();

  for (int i = 0; i < arr.Length(); i++) {
    tempArr.push_back(Napi::Value(arr[i]).ToNumber().Int32Value());
  }

  NSorting::insertion_sort(tempArr);

  Napi::Array returnArr = Napi::Array::New(info.Env(), tempArr.size());

  uint32_t i = 0;
  for (auto& e : tempArr) {
    returnArr[i++] = Napi::Number::New(info.Env(), e);
  }

  return returnArr;
}

Napi::Value GetInsertionSortAnimation(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "require at least one argument")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsArray()) {
    Napi::TypeError::New(env, "require argument as an array")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  std::vector<std::vector<int>> animations;
  std::vector<int> tempArr;
  Napi::Array arr = info[0].As<Napi::Array>();

  for (int i = 0; i < arr.Length(); i++) {
    tempArr.push_back(Napi::Value(arr[i]).ToNumber().Int32Value());
  }

  animations = NSorting::get_insertion_sort_animation(tempArr);

  Napi::Array returnAnimations =
      Napi::Array::New(info.Env(), animations.size());

  uint32_t i = 0;
  for (auto& e : animations) {
    Napi::Array animation = Napi::Array::New(info.Env(), e.size());

    uint32_t ii = 0;
    for (auto& l : e) {
      animation[ii++] = Napi::Number::New(env, l);
    }

    returnAnimations[i++] = animation;
  }

  return returnAnimations;
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "hello"),
              Napi::Function::New(env, Method));
  exports.Set(Napi::String::New(env, "randomIntegers"),
              Napi::Function::New(env, CreateRandomIntegers));
  exports.Set(Napi::String::New(env, "bubbleSort"),
              Napi::Function::New(env, BubbleSort));
  exports.Set(Napi::String::New(env, "insertionSort"),
              Napi::Function::New(env, InsertionSort));
  exports.Set(Napi::String::New(env, "getBubbleSortAnimation"),
              Napi::Function::New(env, GetBubbleSortAnimation));
  exports.Set(Napi::String::New(env, "getInsertionSortAnimation"),
              Napi::Function::New(env, GetInsertionSortAnimation));
  return exports;
}

NODE_API_MODULE(hello, Init);
