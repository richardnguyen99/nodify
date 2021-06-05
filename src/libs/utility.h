/**
 * @file utility.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-06-05
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef NODIFY_UTILITY_H
#define NODIFY_UTILITY_H

#include <napi.h>
#include <random>
#include <vector>

namespace nodify
{
/**
 * @brief Convert native array to JS array
 *
 * @tparam Iter
 * @param info
 * @param begin
 * @param end
 * @return Napi::Value
 */
template <typename Iter>
Napi::Array ToJSArray(const Napi::CallbackInfo &info, Iter begin, Iter end)
{
  Napi::Array jsArray = Napi::Array::New(info.Env(), std::distance(begin, end));

  uint32_t i = 0;
  for (Iter current = begin; current < end; current++)
  {
    jsArray[static_cast<int>(std::distance(begin, current))] = Napi::Number::New(info.Env(), *current);
  }

  return jsArray;
}

/**
 * @brief Generate data contains range that is double number of elements
 *
 * @tparam T
 * @param list_size
 * @return std::vector<T>
 */
template <typename T>
std::vector<T> generate_data(int list_size)
{
  std::mt19937 generator{std::random_device{}()};
  std::uniform_int_distribution<> list_range{0, list_size * 2};

  auto random_data = [&generator, &list_range]() { return list_range(generator); };

  std::vector<T> result;

  for (size_t i = 0; i < list_size; ++i)
  {
    result.push_back(random_data());
  }

  return result;
}
} // namespace nodify

#endif /* NODIFY_UTILITY_H */
