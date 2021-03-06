/**
 * @file Sorting.cc
 * @author Richard Nguyen (github.com/richardnguyen99)
 * @brief Source code for Sorting header.
 * @version 0.1
 * @date 2021-03-05
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>
#include "Sorting.h"

void
NSorting::bubble_sort(std::vector<int>& arr)
{
  // Instead of looping every element, we use
  // a temporary to detect if there is no swapping
  // then stop the loop.
  bool swapped = true;
  while(swapped){
    swapped = false;
    for (size_t i = 0; i < arr.size()-1; i++) {
      if (arr[i]>arr[i+1] ){
        std::swap(arr[i], arr[i+1]);
        swapped = true;
      }
    }
  }
}

std::vector<std::vector<int>>
NSorting::get_bubble_sort_animation(std::vector<int>& arr)
{
  std::vector<std::vector<int>> animations;

  bool swapped = true;
  while(swapped){
    swapped = false;
    for (size_t i = 0; i < arr.size()-1; i++) {
      if (arr[i]>arr[i+1] ){
        std::vector<int> animation;
        animation.push_back(i);
        animation.push_back(i+1);

        animations.push_back(animation);
        std::swap(arr[i], arr[i+1]);
        swapped = true;
      }
    }
  }

  return animations;
}
