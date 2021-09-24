## Array Nesting

You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].

You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:

* The first element in s[k] starts with the selection of the element nums[k] of index = k.
* The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.
* We stop adding right before a duplicate element occurs in s[k].

Return the longest length of a set s[k].

dfs for each value? and return the longest one?

yes ac. Because there is no extra edge in this problem. Actually if this is a graph problem and contains some circle, it's more complicated to solve. Then we need to use Tarjan to do it.

## Break a Palindrome

iven a palindromic string of lowercase English letters palindrome, replace exactly one character with any lowercase English letter so that the resulting string is not a palindrome and that it is the lexicographically smallest one possible.

Return the resulting string. If there is no way to replace a character to make it not a palindrome, return an empty string.

A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, a has a character strictly smaller than the corresponding character in b. For example, "abcc" is lexicographically smaller than "abcd" because the first position they differ is at the fourth character, and 'c' is smaller than 'd'.

So, I think we can replace the second symmetry character with the words after dic.

the std is to find the first character not in the middle place and replace it with the b.

If all of them are then replace the last one as b.

AC.