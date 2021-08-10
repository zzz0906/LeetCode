## Palindrome Partitioning II

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

132 I have done before. 

```
NOPE!! **DP** again! f[i] represent from 0-i the minimum cuts needed.

for [0-i] we can transfered from [0-j] and [j+1,i] and we can know that the minimum cuts can be f[j]

and when f[j+1,i] is a palindrome then we can get the minimum cuts. we for loop all before value. 

Because the ansewr must be transfered from before cut in j and then cut in j!

Also, we use a p[i][j] to record whether it's a palindrome form i to j

and p[i][j] = (s[i] == s[j]) && p[i+1][j-1] 

Then we can update when p[j+1,i] then f[j] + 1
```

I think it's a memory-based search. Init it, if it's a palindrome f[i,j] = 1. O(n^2) for initialize.

And f[0..i] => f[0..j], f[j..i] => can be simplfied. Because, if we can split f[0..k] (k > j) and k..i is a palindrome. Then, we can ensure that 0..k must be f[k] + 1. Thus, we can use one dimensional for this question.

## Rank Transform of a Matrix

Given an m x n matrix, return a new matrix answer where answer[row][col] is the rank of matrix[row][col].

The rank is an integer that represents how large an element is compared to other elements. It is calculated using the following rules:

The rank is an integer starting from 1.

If two elements p and q are in the same row or column, then:

If p < q then rank(p) < rank(q)

If p == q then rank(p) == rank(q)

If p > q then rank(p) > rank(q)

The rank should be as small as possible.

It is guaranteed that answer is unique under the given rules.

First, we can observe that the minimum rank 1 is the minimum number both in row and column.

I think the order of the row and column in a matrix is the rank. But we need to start from the global minimum number for the whole matrix.

this number can be set as 1.

Hint: Handle the equal cells by treating them as components using a union-find data structure.

m == matrix.length
n == matrix[i].length
1 <= m, n <= 500
-109 <= matrix[row][col] <= 10^9

the minimum one in its row and column must can be set as 1.

let me think about a solution. we enumerate rank r from 1 until all. And summary the maximum number of number less than current number in row and column. this value is k, its value is k + 1. if k + 1 = r, the we can assign it. 

oh godness, I cannot finish it in half of an hour. let me see the std?

the std uses union find and map.

first sort the whole matrix and Group cells by their values, process groups (cells that have the same value) in ascending order (smaller number has smaller rank).

For cells that are in the same row or same cols union them using union find, they should have the same rank which equals to max(max_rank_x[cols], max_rank_y[rows]) + 1.

the key problem for this one is how to process the same value. For example, with value 3 it has 1,3 1,5, 3,5, 9,9 we shall process (1,3,1,5,3,5)

we use a vector to record the uniond find's father's all son's positions. And process them together to use the maximum rank.

This problem is harder. I think it's a really valuable problem.

## Add Strings

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

Arbitrary-precision arithmeti. just simulate the process of add.

yes ac. Pay attention to reverse the string to perform add operation.

## Flip String to Monotone Increasing

A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).

You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

Return the minimum number of flips to make s monotone increasing.

```
Example 1:

Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.
```