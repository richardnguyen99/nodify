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
 * @brief Insertion sorting algorithm
 *
 * This method only sorts the input array
 * using insertion sorting. This sorts the
 * array directly.
 *
 * @param arr Container of integer values
 */
void insertion_sort(std::vector<int>& arr);

/**
 * @brief Get the bubble sort animation object
 *
 * This will listen to the bubble sort algorithm
 * and returns the swapping between two values.
 * This also mutates the actual array.
 *
 * @param arr
 * @return std::vector<std::vector<int>>
 */
std::vector<std::vector<int>> get_bubble_sort_animation(std::vector<int>& arr);

/**
 * @brief Get the insertion sort animation object
 *
 * This will  listen to the insertion sort algorithm
 * and returns the comparing and swapping indices
 * between two values.
 * This also mutates the actual array.
 *
 * @param arr
 * @return std::vector<std::vector<int>>
 */
std::vector<std::vector<int>> get_insertion_sort_animation(
    std::vector<int>& arr);
}  // namespace NSorting

#endif /* NODIFY_SORTING_H */
