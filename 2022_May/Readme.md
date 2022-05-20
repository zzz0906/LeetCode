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