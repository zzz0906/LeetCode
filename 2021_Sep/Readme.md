## Array Nesting

You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].

You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:

* The first element in s[k] starts with the selection of the element nums[k] of index = k.
* The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.
* We stop adding right before a duplicate element occurs in s[k].

Return the longest length of a set s[k].

dfs for each value? and return the longest one?

yes ac. Because there is no extra edge in this problem. Actually if this is a graph problem and contains some circle, it's more complicated to solve. Then we need to use Tarjan to do it.