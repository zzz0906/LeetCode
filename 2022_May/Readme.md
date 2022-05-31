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

## 32. Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

I have done it before. 

DP problem. It's very hard to understand why we need to itearte when s[j] = ')'  plus 2 plus the variable DP[j] before.

## 1342. Number of Steps to Reduce a Number to Zero

Given an integer num, return the number of steps to reduce it to zero.

In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

just simulation until it turn into zero.

AC.

But the std use a bit operation to accelearte the process. 100 means we need three step, each step move a zero and when facing a last 1 we minus 1 then move a zero. I think this is core idea.  Thus overall we need number of 1 * 2 + number of zero step.

## 318. Maximum Product of Word Lengths

Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0

I have done it before. The brute force way is to compare any two string to see if they have common character. If not, try to use compare the product of length fo these two string with the result. Overall, the time complexity will be O(N\*M\*length*\length). 

The question turn into how to check containing common character quickly. we can use a 26 array to represent each string. Then complixy will O(N\*N\*26) 1000000\*26; Or if we can use bit mask, we can use an 26 integer to represent the number. Then the complixy will be N*N. Yes, it seems the optimal solution. Let me see how I finished it before. Oh...N\*N\*26. Let me use bit mask this time. AC!

## 29. Divide Two Integers

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than $-2^31$, then return $-2^31.$

It's interesting. The std ansewr is using algorithm - quick power. we can use minus each time until the result value > 0. But we need to take the result very carefully if both negative, we can turn them into both positive. If one of them are negative we can turn one into positive and time a positive symbol in the end.

TLE...we shall use bit operation. 

The labs() function in C++ returns the absolute value of a long or long int data. The labs() function can be thought as the long int version of abs(). It is defined in <cstdlib> header file.

We transfer it to the longer abs value. And then we use a quick power. Each time we minus divisor * 2 == divisor << 2 Until we cannot afford this minus because it will turn into a negative number. For example

17 / 3 = 5 => 3 << 2 1 << 2 = 4 + 1 = 5

So we just find the maximal even number the divisor can multiply to reach a value which is still less and equal than the dividend. We repeat our process. And the thing we try to do is to construct the binary form of the answer. And use bit operation to get its back.

AC!

## 1461. Check If a String Contains All Binary Codes of Size K

Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

If a string needs to contain all the binary code of length k, such as 0 we shall have 00 01 10 11 if we can share some substring of these strings, we can know that it at least has 00110 five characters. 

The brute force way is to detect each combination one by one. 

Let me see the std's ansewr directly, it use a hashset to insert all the length-k strings. Because it only contain 0,1, the length-k  non-duplicate strings must equal to 2^k. If not, we can just return false.