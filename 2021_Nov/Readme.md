## 130. Surrounded Regions

Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

[also done before](../Insights/130.md)

We know that if a O in the matrix contains a 'O', it must connect to the edge. The solution dfs from the edge position and turn all these O into $. And finally, this $ will turn into O and others will all be X!

YES. AC!

## 980. Unique Paths III

You are given an m x n integer array grid where grid[i][j] could be:

* 1 representing the starting square. There is exactly one starting square.
* 2 representing the ending square. There is exactly one ending square.
* 0 representing empty squares we can walk over.
* -1 representing obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

It's a DP problem? or a discrete mathematical problem? we can use all possible - the solution through the obstacle.

I also have done it before. Must every day problem before. 

OH, i know, we need to walk over every single block once. It's a pure brute force. We can assign the node we have been to as -1. And after dfs we restore it. And we store a pathcount and dfs them. Also, I use a zerocount to count all zero blocks. Only if the pathzerocount == zerocount, which mean we have been to all 0 blocks, then the answer count will add 1.

## 129. Sum Root to Leaf Numbers

[also done before](../Insights/129.md)

when we reach the leaf, add the number we accumulated.

## 404. Sum of Left Leaves

similar easy question. Just add the left child into the res.

## 441. Arranging Coins

You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

Find the maximum kk such that $\frac{k (k + 1)}{2} \le N$

$k = \sqrt{(2*N + \frac{1}{4})} - \frac{1}{2}$

AC.