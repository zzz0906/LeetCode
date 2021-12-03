## 198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

classical DP problem. [done before](../Insights/198.md)

we can know that if we want to steal f[i], 

i-3,i-2,i-1,i

if we steal i, we can transfer from steal i-2, but if we steal i-2, we cannot steal i-3, thus, we can choose i-2 (not i-3 and i-1) or i-3
because we must steal i (assumption for dp[i]). Thus, f[i] can only transfered from i - 2 and i - 3. We shall prepare three elements in the array as init.

## 328. Odd Even Linked List

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

I have [done it before](../Insights/328.md)

value switch? one pointer move one step a time, and another only move the odd number? nope the even number will be replaced. oh i know!!!

ues 1 as the head of the odd number's linked list andd 2 as the even, and move two steps each time and link them again, and finally we link 1 2toghether! but my code is too ugly. let me find some others.

I find a std who impelement my idea perfect!

* use 1 as the odd head, 2 as even number
* move two step each time and link them
* link 1 and 2

## 152. Maximum Product Subarray

Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

It is guaranteed that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

[done before](../Insights/152.md) we can use the prefix product, but there will be some zero, for example, 1,0,5,3,4. The std answer use dp. Because continous array must have an ending. we use f[i] to represent the maximum continous array ending in the i. because the negative value will turn into positive biggest. Thus, we store a minimum and maximum as the dp value. We can get three values - f[i] = f1[i-1]*nums[i], nums[i], f2[i-1]*nums[i].
