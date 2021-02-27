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

void bubbleSort(std::vector<int>& a)
{
  bool swapp = true;
  while(swapp){
    swapp = false;
    for (size_t i = 0; i < a.size()-1; i++) {
      if (a[i]>a[i+1] ){
        std::swap(a[i], a[i+1]);
        swapp = true;
      }
    }
  }
}
