#ifndef _UTILITY_H
#define _UTILITY_H

#include <vector>
#include <random>

template<typename T, typename TCreator>
std::vector<T> randomVectorObjects(TCreator creator)
{
  std::mt19937 generator{ std::random_device{}() };
  std::uniform_int_distribution<> listSizeDist{ 15, 30 };

  auto listSize = listSizeDist(generator);
  std::vector<T> values;

  for (int i = 0; i < listSize; i++)
  {
    values.push_back(creator());
  }

  return values;
}

std::vector<int> randomIntegers();

#endif
