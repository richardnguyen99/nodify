/**
 * @file Sorting.h
 * @author Richard Nguyen (github.com/richardnguyen99)
 * @brief
 * @version 0.1
 * @date 2021-03-05
 *
 * @copyright Copyright (c) 2021
 *
 * Sorting headers for sorting algorithms
 */

#ifndef NODIFY_SORTING_H
#define NODIFY_SORTING_H

#include <vector>

namespace NSorting {
  /**
   * @brief Bubble sorting algorithm
   *
   * This method only sorts the input array
   * using bubble sorting. This sorts the array
   * directly.
   *
   * @param arr Container of integer values
   */
  void bubble_sort(std::vector<int>& arr);

  /**
   * @brief Get the bubble sort animation object
   *
   * This will listen to the bubble sort algorithm
   * and returns the swapping between two values
   *
   * @param arr
   * @return std::vector<std::vector<int>>
   */
  std::vector<std::vector<int>> get_bubble_sort_animation(std::vector<int>& arr);
}

#endif /* NODIFY_SORTING_H */
