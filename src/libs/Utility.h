/**
 * @file Utility.h
 * @author Richard Nguyen
 * @brief Utility header for configurations and helper functions
 * @version 0.1
 * @date 2021-03-08
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef NODIFY_UTILITY_H
#define NODIFY_UTILITY_H

#include <ostream>
#include <random>
#include <vector>

namespace Utility {
/**
 * @brief Output overloading that helps print out std::vector.
 *
 * This function is only useful in command lines and terminals
 * for raw-testing C++ files.
 *
 * @tparam T
 * @param out
 * @param data
 * @return std::ostream&
 */
template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> data)
{
  out << "[\n";
  for (const auto& elem : data) {
    out << "\t" << elem << ",\n";
  }
  out << "]";
  return out;
}

/**
 * @deprecated Use std::swap instead
 *
 * @tparam T
 * @param a
 * @param b
 */
template <typename T>
void swap(T& a, T& b)
{
  T temp = a;
  a = b;
  b = temp;
}

/**
 * @brief Create a random object with mt19937 with a specfied length
 *
 * @tparam T
 * @tparam TCreator
 * @param creator
 * @param listSize
 * @return std::vector<T>
 */
template <typename T, typename TCreator>
std::vector<T> randomVectorObjects(TCreator creator, int listSize)
{
  std::mt19937 generator{std::random_device{}()};

  std::vector<T> values;

  for (int i = 0; i < listSize; i++) {
    values.push_back(creator());
  }

  return values;
}

/**
 * @brief Create a random object with mt19937 without specfied length
 *
 * @tparam T
 * @tparam TCreator
 * @param creator
 * @return std::vector<T>
 */
template <typename T, typename TCreator>
std::vector<T> randomVectorObjects(TCreator creator)
{
  std::mt19937 generator{std::random_device{}()};
  std::uniform_int_distribution<> listSizeDist{15, 30};

  auto listSize = listSizeDist(generator);
  std::vector<T> values;

  for (int i = 0; i < listSize; i++) {
    values.push_back(creator());
  }

  return values;
}

/**
 * @brief Return a slice or a sub-vector
 *
 * @tparam T
 * @param v original vector
 * @param m start index
 * @param n end index
 * @return std::vector<T>
 */
template <typename T>
std::vector<T> slice(std::vector<T>& v, int m, int n)
{
  std::vector<T> vec(n - m + 1);
  std::copy(v.begin() + m, v.begin() + n + 1, vec.begin());
  return vec;
}

/**
 * @brief Helper function of randomVectorObjects for integers
 *
 * @param listSize
 * @return std::vector<int>
 */
std::vector<int> randomIntegers(int listSize);
}  // namespace Utility

#endif /* NODIFY_UTILITY_H */
