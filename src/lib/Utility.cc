#include <algorithm>
#include "Utility.h"

std::vector<int> randomIntegers()
{
  std::mt19937 generator{ std::random_device{}() };
  std::uniform_int_distribution<> dist{ 0, 100 };

  auto creator = [&generator, &dist]() {
      return dist(generator);
  };

  return randomVectorObjects<int, decltype(creator)>(creator);
}
