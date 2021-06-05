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
  std::vector<int[3]> sorting;
};

/**
 * @brief Get the bubble sort animation object
 *
 * 0: comparison
 * 1: swapping
 * -1: terminating
 *
 * @tparam Iter
 * @param begin
 * @param end
 * @param animation
 */
template <typename Iter>
void get_bubble_sort_animation(Iter begin, Iter end, Animation &animation)
{
  bool swapping = true;

  while (begin != end-- && swapping)
  {
    swapping = false;

    for (Iter current = begin; current != end; ++curent)
    {
      animation.push_back({0, current, current + 1});
      if (*(current + 1) < *current)
      {
        animation.push_back({1, current, current + 1});
        std::iter_swap(current, current + 1);
        swapping = true;
      }
    }
  }

  animation.push_back({-1, 0, 0});
}
} // namespace nodify

#endif /* NODIFY_ANIMATION_H */
