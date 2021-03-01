#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"

int main()
{
  auto randomArr = randomIntegers();

  std::cout << randomArr << std::endl;

  bubbleSort(randomArr);

  std::cout << randomArr << std::endl;

  return 0;
}
