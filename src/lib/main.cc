#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Sorting.h"

using Utility::operator<<;

int main()
{
  auto randomArr = Utility::randomIntegers(10);

  std::cout << randomArr << std::endl;

  std::vector<std::vector<int>> animations = NSorting::get_bubble_sort_animation(randomArr);

  std::cout << animations << std::endl;

  return 0;
}
