## Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

typical DP. f[i,j] means the maximum common subsequence before i and j. Thus, DP[i][j] will come from DP[i-1][j-1] + 1 or DP[i][j-1], DP[i-1][j] 's maximum

AC!

## 201. Bitwise AND of Numbers Range

I have submitted this problem before, just remember if the length diff is bigger than 1, which means that the beginning of the bit form is 1&0 = 0; it must have corss a total diff form because it carry a number to the head.[100 - 1000]

## 543. Diameter of Binary Tree

we can dfs two path for a node. And store the length1 + length2 as a path. And compare the path to the answer. We only store the maximum answer which shall be diameter.

yes, ac!

## 374. Guess Number Higher or Lower

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns 3 possible results:

-1: The number I picked is lower than your guess (i.e. pick < num).
1: The number I picked is higher than your guess (i.e. pick > num).
0: The number I picked is equal to your guess (i.e. pick == num).

Return the number that I picked.

I also have done before. just binary search.

## 1008. Construct Binary Search Tree from Preorder Traversal

Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right

so given a A....[smaller than A] we cecusive call smaller than A and take them as the left tree of A.

let's do this.

AC

## 279. Perfect Squares

279. done before!

## 309

also done before... DP

DP record current money. And use buy,sold,rest to do the DP. I thnik this question is hard.

buy[i] means we bought a stock before ith day's maximum profit.

sell[i] means we sold a stock before ith day's maximum profit.

rest[i] means we are coll down in ith day's maximum profit.

buy[i]  = max(rest[i-1] - price, buy[i-1]), sell[i] = max(buy[i-1] + price, sell[i-1]), rest[i] = max(sell[i-1], buy[i-1], rest[i-1])

## 123. Best Time to Buy and Sell Stock III

still do it before. it's still a dp. 

* l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
* g[i][j] = max(l[i][j], g[i - 1][j]);

## 437. Path Sum III

Finished it before. Why all the problems are done before in these three days? Strange...

make a array to record father's sum and count how many elements that add current value eqaul to target. Also, do not forget zero add current value.

## 993. Cousins in Binary Tree

Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

I found hard to return the depth from the dfs

we can use a `pass by value` to solve this problem and compare them in a same dfs.

## 496. Next Greater Element I

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

we can use a map to do the o(n) tiem complexity?

nope, we still need to iterate the following index after current to find the next big one.

let me see the std's solution. oh, it's the same.