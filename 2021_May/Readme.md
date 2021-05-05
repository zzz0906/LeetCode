## Non-decreasing Array

Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

It's not an easy question. if we can modify one element, how shall we choose this element?

5 7 1 8

3 6 0

-1 4 2 3

Let me see the std. 


(4)，2，3

-1，(4)，2，3

2，3，3，(2)，4

small bigger we need to modify current one 3 2 4 => 3 3 4 i - 1 = i - 2;  if nums[i] < nums[i - 2] => 3 5 0 => 3 5 5 i = i - 1 

