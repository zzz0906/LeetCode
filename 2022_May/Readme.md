## 1641. Count Sorted Vowel Strings

Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

It's kind like a problem of permutation. First character we can have 5 choice, and for each choice we can have also 5 choice which is 5 + 4 + 3 + 2 + 1

And Thinking about choice 2, for first choice 5 + 4 + 3 + 2 + 1, for each we can generate 3 permutation when we have length-3 string we can have

(5 + 4 + 3 + 2 + 1) + (4 + 3 + 2 + 1) + (3 + 2 + 1)

And for the length 4, for each 5,4,3,2,1 in the first we can have a 5 + 4 + 3 + 2 + 1

5  4  3 2 1
15 10 6 3 1

so that we can record the number of 5,4,3,2,1 and accumulate to the next answer. let me try. so each last term 5 can cotribute an extra 4 3 2 1 for the next iteration, is that correct?

Oh no, it's incorrect. Let me see the answer.

the answer is's clear that 'o' can connect all the string which are less than 'u'. Therefore, each time the number of string starting from o is o += u; i += o; So each new string can be connected with the string who is less than current one's sum. And each time we accumulated it to the proceeding one. AC!

## 63. Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

I think I have done it before, It's just a DP problem. The current one can come from the left one and upper one. And if current is obstacle the results shall be 0. It means no path can pass the obstacles.

## 474. Ones and Zeroes

You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

I have done this before. Let me try to think about it at first. The first idea jump into my mind is to transfer 0,1 binary to 0: count 1: count. It becomes a knapsack problem. The value turn into the numebr of the items we want to load. It's a dp problem? x1 + x2 + x3 <= m y1 + y2 + y3 <= n maximize |x|. Greedy cannot handle it. Definitely. 

f[i,j,k] means for the current i items, we use j 1 and k 0. and the dimension i we can save. Because we only forward i loop.

600\*600\*100\*100 = 3600000000, we need to optimize it. we only need to store the past maximum value. It means for the current item, it must be dervied from i - 1. In this situation, the answer will be o(600\*100\*100 = 6000000)

yes, i am correct. But my code is so ugly. the std use another dp array. array means the number of m,n can represent the maximum number of string. We know that, currently, we have to use m and n 1 and 0, it means in the before we only can use at most i - m, j - n's ones and zeros. f[i][j] = max(f[i][j], f[i - m][j- n] + 1). 

Yes, this is knapsack problem!