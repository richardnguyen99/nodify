/**
 * @file Utility.cc
 * @author Richard Nguyen
 * @brief Utility source for configurations and helper functions
 * @version 0.1
 * @date 2021-03-08
 *
 * @copyright Copyright (c) 2021
 */
#include "Utility.h"
#include <math.h>
#include <algorithm>

std::vector<int> Utility::randomIntegers(int number)
{
  std::mt19937 generator{std::random_device{}()};
  std::uniform_int_distribution<> dist{0, 100};

  auto creator = [&generator, &dist]() { return dist(generator); };

  return Utility::randomVectorObjects<int, decltype(creator)>(creator, number);
}
