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

## 337. House Robber III

[done before] but in another daily challenge

just dfs and we compare root + left left + left right + right right + right left and root left + root right! (we cannot steal adjacent)

and use a unordered map as the memory search.

AC!

## 1290. Convert Binary Number in a Linked List to Integer

I remember I have done it before in a daily challenge.

Actually it's easy. just store the exp and multiply it to the answer.

## 1306. Jump Game III

Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

DP? I remember I have done this problem in high school.

this is a graph. And we to know whether index 0 can reach each nodes. Can we use dfs? it most have 2*5*10^4 nodes and edges. I guess so. we can use such solution.

we build the graph and start from the nodes and we do not traverse the same node twice.

yep, ac. And when we reach zero, we return all the dfs stack.

## 416. Partition Equal Subset Sum

done before. the problem only need to divide the array into two subset.

* 1 <= nums.length <= 200
* 1 <= nums[i] <= 100

the sum can be treated as the index of array. we can use f[sum - i] | f[i] to update the f[i]

## 938. Range Sum of BST

Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

dfs and determine whether the sum is between the range sum?