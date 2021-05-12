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

## Jump Game II

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

It's clear a DP.

DP[i] must come from the last node with minimum jump steps.

so a dp[i] can update i + [1 - nums[i]]'s interval

## Convert Sorted List to Binary Search Tree

Interesting can we just split from the middle?

let me see the std solution. 

...I have done this problem before. 

yep, it's my idea. first, calculate the right then left. And we will use mid to constuct a tree. 

But given a list, we need to transfer the list to the array. Then we can perform our cut in the middle!

## Maximum Points You Can Obtain from Cards

There are several cards arranged in a row, and each card has an associated number of points The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

head or end. It's a DP?

HINT: Keep a window of size n - k over the array. The answer is max(answer, total_pts - sumOfCurrentWindow)

the hint2 is too Celever! It basically tell you how to do.

Yes AC. Use a prefix sum and slides window. O(n).