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

#include "Sorting.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include "Utility.h"

void NSorting::bubble_sort(std::vector<int>& arr)
{
  // Instead of looping every element, we use
  // a temporary to detect if there is no swapping
  // then stop the loop.
  bool swapped = true;
  while (swapped) {
    swapped = false;
    for (size_t i = 0; i < arr.size() - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        std::swap(arr[i], arr[i + 1]);
        swapped = true;
      }
    }
  }
}

void NSorting::insertion_sort(std::vector<int>& arr)
{
  // No need to compare the first element
  // So start with i = 1
  for (int i = 1; i < arr.size(); i++) {
    auto key = arr[i];
    int j = i - 1;

    while (j >= 0 && key < arr[j]) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

std::vector<std::vector<int>> NSorting::get_bubble_sort_animation(
    std::vector<int>& arr)
{
  std::vector<std::vector<int>> animations;

  for (int i = 0; i < arr.size() - 1; i++) {
    for (int j = 0; j < arr.size() - i - 1; j++) {
      // 0: List of two indices for comparing
      animations.push_back({j, j + 1});

      if (arr[j] > arr[j + 1]) {
        // 1: Use 1 for swapping that current index
        animations.push_back({j, j + 1});
        std::swap(arr[j], arr[j + 1]);
      }
      else {
        // 1: Use 0 for not swapping
        animations.push_back({j, j});
      }

      // 2: List of two indices that will be converted back
      // to normal indices.
      animations.push_back({j, j + 1});

      if (j == arr.size() - i - 2) {
        animations.push_back({static_cast<int>(arr.size()) - i - 1, 1});
      }
      else {
        // dummy
        animations.push_back({j + 1, 0});
      }
    }
  }

  return animations;
}

std::vector<std::vector<int>> NSorting::get_insertion_sort_animation(
    std::vector<int>& arr)
{
  std::vector<std::vector<int>> animations;

  for (int i = 1; i < arr.size(); i++) {
    bool isSorted = false;
    int key = arr[i];
    for (int j = i - 1; j >= 0 && !isSorted; j--) {
      // 0: for comparison
      animations.push_back({j, j + 1, 0});
      if (key < arr[j]) {
        // 1: swapped
        std::swap(arr[j], arr[j + 1]);
        animations.push_back({j, j + 1, 1});
      }
      else {
        // 1: no swapping
        animations.push_back({j, j + 1, 0});
      }

      // 2: convert back to normal
      animations.push_back({j, j + 1, 2});

      // 3: mark this as sorted
      std::vector<int> copied_arr = Utility::slice(arr, 0, i);
      isSorted = std::is_sorted(std::begin(copied_arr), std::end(copied_arr));
      animations.push_back({j, i, isSorted ? 3 : 0});
    }
  }

  return animations;
}
