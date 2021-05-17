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

## Range Sum Query 2D - Immutable

prefix sum? A - B - C + D(the most left upper)

304. Which I have finished it before. But I use a less efficient way. I calculate prefix sum for each row. Not for the whole matrix. 

## Ambiguous Coordinates

We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)".  Then, we removed all commas, decimal points, and spaces, and ended up with the string s.  Return a list of strings representing all possibilities for what our original coordinates could have been.

Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented with less digits.  Also, a decimal point within a number never occurs without at least one digit occuring before it, so we never started with numbers like ".1".

The final answer list can be returned in any order.  Also note that all coordinates in the final answer have exactly one space between them (occurring after the comma.)

we can add 2 . and 1; And the answer is (length of string)^3 if we use brute force. But we need to summary all special situation. I use std's solution directly.

if S == "": return []

if S == "0": return [S]

if S == "0XXX0": return []

if S == "0XXX": return ["0.XXX"]

if S == "XXX0": return [S]

return [S, "X.XXX", "XX.XX", "XXX.X"...]

It's a DFS idea. First we find the position of ,. Then we try to add . in this two number. 

And we combine these two '.' 's situation. 

So the time complexity is O(length)^3;

## Binary Tree Camera

Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor its parent, itself, and its immediate children.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

we shall install all even nodes. so the problem is to count the nodes in even level. 

Nope...it's incorrect.

DP? f[i,0] f[i,1] to represent install and uninstall camera. Thus, f[son,0]

fuck...bull shit. It's a greedy algorithm. The leaf's father shall be put a camera.

the std use 2 to represent the leaf's son or grandpa' node.

leaf->camera->granpa->leaft

0->1->2-> (because his son is both 2) we shall return 0