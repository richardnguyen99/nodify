/**
 * @file sorting.h
 * @author Richard Nguyen (richard.ng0616@gmail.com)
 * @brief Header for sorting algorithms
 * @version 0.1
 * @date 2021-06-04
 *
 * @copyright Copyright (c) 2021
 */

#ifndef NODIFY_SORTING_H
#define NODIFY_SORTING_H

#include <napi.h>

namespace nodify
{
/**
 * @brief Bubble sort implementation using iterators
 *
 * @tparam iter
 * @param begin
 * @param end
 */
template <typename iter>
void bubble_sort(iter begin, iter end)
{
  // Flag to terminate the algorithm when there is
  // no swap happening
  bool swapping = true;

  //
  while (begin != end-- && swapping)
  {
    swapping = false;

    for (iter current = begin; current != end; ++current)
    {
      // Compare two adjacent values
      if (*(current + 1) < *current)
      {
        std::iter_swap(current, current + 1);
        swapping = true;
      }
    }
  }
  return;
}

/**
 * @brief Insertion sort implementation using iterators
 *
 * @tparam iter
 * @param begin
 * @param end
 */
template <typename iter>
void insertion_sort(iter begin, iter end)
{
  if (begin == end)
  {
    return;
  }

  for (iter next = std::next(begin); next != end; ++next)
  {
    for (iter current = next; current > begin; --current)
    {
      iter prev = std::prev(current);

      if (*current < *prev)
      {
        std::iter_swap(current, prev);
      }
      else
        break;
    }
  }
}

template <typename iter>
void selection_sort(iter begin, iter end)
{
  bool swapping = true;
  for (; begin != end && swapping; begin++)
  {
    swapping = false;
    iter smallest = begin;

    for (iter current = smallest; current != end; current++)
    {
      if (*current < *smallest)
      {
        smallest = current;
      }
    }

    if (smallest != end)
    {
      swapping = true;
      std::iter_swap(begin, smallest);
    }
  }
}

template <typename iter>
void quick_sort(iter begin, iter end)
{
  if (std::distance(begin, end) > 1)
  {
    iter pivot = begin;
    iter bound = std::next(begin);

    for (iter next = std::next(begin); next < end; ++next)
    {
      if (*next < *pivot)
      {
        std::iter_swap(next, bound);
        bound++;
      }
    }

    std::iter_swap(begin, bound - 1);

    quick_sort(begin, bound - 1);
    quick_sort(bound, end);
  }
}
} // namespace nodify

#endif /* NODIFY_SORTING_H */
