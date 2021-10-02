## Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

typical DP. f[i,j] means the maximum common subsequence before i and j. Thus, DP[i][j] will come from DP[i-1][j-1] + 1 or DP[i][j-1], DP[i-1][j] 's maximum

AC!
