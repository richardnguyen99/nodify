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

void bubbleSort(std::vector<int>& arr)
{
  int size = arr.size();

  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size-i-1; j++)
    {
      swap(arr[i], arr[j+1]);
    }
  }
}
