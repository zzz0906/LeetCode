## 300. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Classical qustion. I definitely have done this. But I think if we use dp dicretly, it should be $O(n^2)$  How can we adjust it to nlogn?

Because we need to the head who is smaller than currecnt value & sequence shall be longer than currecnt value. Thus we can have priority queue, whose sequential length is short & value is bigger is useless.

Let me see my past std solution.

the std solution looks like a greedy + binary search soluton. We just want to build the seq according to binary search to find the insert place otherwise we can replace the last element directly.

## 823. Binary Trees With Factors

Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

* 1 <= arr.length <= 1000
* 2 <= arr[i] <= 109
* All the values of arr are unique.

This question I will still try to use go to solve it.

The std use a dp...interesting.

Let me use python I seem not using python for such a long time.

Method: DP

Since the parent node is the product of the children, the value of the parent nodes must larger than the values of its children.

Thus, we can sort the arr first, and start to calculate the combination of products from smallest node to the largest one.

For example, arr = [18, 3, 6, 2]

After sorting, arr = [2, 3, 6, 18]

Then, a dict count_product_dict needs to be created to store the count of combinations and all the initial values should be 1.

Because all the values are unique thus we can make a dict at first.

Thus we can know that each time we will update the sub-tree by the number of child tree's multiplication. And each time we will do the modular unitl we get the final answer.

## 108. Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Just use the middle point as the cut and repeat the process unitl we only have one element or null element.