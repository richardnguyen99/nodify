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
template <typename Iter>
void bubble_sort(Iter begin, Iter end)
{
  bool swapping = true;

  while (begin != end-- && swapping)
  {
    swapping = false;

    for (Iter current = begin; current != end; ++current)
    {
      if (*(current + 1) < *current)
      {
        std::iter_swap(current, current + 1);
        swapping = true;
      }
    }
  }
  return;
}

template <typename Iter>
void insert_sort(Iter begin, Iter end)
{
  if (begin == end)
  {
    return;
  }

  for (Iter next = std::next(begin); next != end; ++next)
  {
    Iter prev = std::prev(current);

    if (*current < *prev)
    {
      std::iter_swap(current, prev);
    }
    else
      return;
  }
}

template <typename T>
void selection_sort(Iter begin, Iter end)
{
  bool swapping = true;
  for (; begin != end && swapping; begin++)
  {
    swapping = false;
    Iter smallest = begin;

    for (Iter current = smallest; current != end; current++)
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
} // namespace nodify

#endif /* NODIFY_SORTING_H */
