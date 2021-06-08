/**
 * @file animation.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-06-05
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef NODIFY_ANIMATION_H
#define NODIFY_ANIMATION_H

#include <vector>

namespace nodify
{
struct Animation
{
  std::vector<std::vector<int>> sorting;
};

/**
 * @brief Get the bubble sort animation object
 *
 * 0: comparison
 * 1: swapping
 * -1: terminating
 *
 * @tparam iter
 * @param begin
 * @param end
 * @param animation
 */
template <typename iter>
void get_bubble_sort_animation(iter begin, iter end, Animation &animation)
{
  bool swapping = true;

  while (begin != end-- && swapping)
  {
    swapping = false;

    for (iter current = begin; current != end; ++current)
    {
      int index = static_cast<int>(std::distance(begin, current));

      animation.sorting.push_back({0, index, index + 1});
      if (*(current + 1) < *current)
      {
        animation.sorting.push_back({1, index, index + 1});
        std::iter_swap(current, current + 1);
        swapping = true;
      }
    }
  }
  animation.sorting.push_back({-1, 0, 0});
}

template <typename iter>
void get_insertion_sort_animation(iter begin, iter end, Animation &animation)
{
  if (begin == end)
    return;

  for (iter next = std::next(begin); next != end; ++next)
  {
    for (iter current = next; current > begin; --current)
    {
      iter prev = std::prev(current);
      int prev_index = static_cast<int>(std::distance(begin, prev));
      int current_index = static_cast<int>(std::distance(begin, current));

      animation.sorting.push_back({0, current_index, prev_index});
      if (*current < *prev)
      {
        animation.sorting.push_back({1, current_index, prev_index});
        std::iter_swap(current, prev);
      }
      else
      {
        break;
      }
    }
  }
}

template <typename iter>
void get_selection_sort_animation(iter begin, iter end, Animation &animation)
{
  bool swapping = true;

  for (iter temp = begin; temp != end && swapping; temp++)
  {
    swapping = false;
    iter smallest = temp;
    int temp_index = static_cast<int>(std::distance(begin, temp));
    int smallest_index = static_cast<int>(std::distance(begin, smallest));

    // Mark this as the smallest node
    animation.sorting.push_back({2, smallest_index, 1});

    for (iter current = smallest; current != end; current++)
    {
      int current_index = static_cast<int>(std::distance(begin, current));

      // Mark this as the compare process
      animation.sorting.push_back({0, smallest_index, current_index});
      if (*current < *smallest)
      {
        smallest = current;
        smallest_index = static_cast<int>(std::distance(begin, smallest));

        // New smallest mark
        animation.sorting.push_back({2, smallest_index, 1});
      }
    }

    if (smallest != end)
    {
      swapping = true;

      // Mark swapping
      animation.sorting.push_back({1, temp_index, smallest_index});
      std::iter_swap(temp, smallest);
    }
  }
}
} // namespace nodify

#endif /* NODIFY_ANIMATION_H */
