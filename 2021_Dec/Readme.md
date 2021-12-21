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

## 147. Insertion Sort List

done before! simulate insertion. be careful with linked list implementation.

## 310. Minimum Height Trees

A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

It's clear we shall use the middle point of the key path in the tree.

[done before](../Insights/310.md) 

yep, but the correct answer is to use topology sort. we need to push_back the vertex with more degree as more as possible. And we shall sort to unitl we have only 2 vertices. because less degree, more nodes means more nodes are in the depth places, thus we need to do the topolgy sort.

## 221. Maximal Square

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Interesting, I have no idea even I have done this before. Let me see my past solution. I use a 2d array - answer to store the maximum square we can build using this node as the most right down cornor nodes.

Using this condition, we do not need to check the 1 and 0 of the sqaures above. Because, we can use f[i-1][j-1] => to expand current i,j. But we shall check the matrix from f[i-1][j-1] => last line's maximal square, f[i-1][j-1] most right 1 because it's 1's sqaure, we need to j - check most right 1 - j is still all 1. If not, we need to find the nearest 0 and break. In the same way, we can find the longest vertical 1 for the column j. And because we have use f[i-1][j-1] to represent the square in the left upper square. If our check all of them are 1, then the maximal square for i,j is f[i-1,j-1] ohterwise f[i,j] is the minimal of (column's longest 1 and row's longest 1).

AC!

## 1200. Minimum Absolute Difference

Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. 

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr

2 <= arr.length <= 10^5
-10^6 <= arr[i] <= 10^6

sort it and then the minimum absolute diff will be the adjacent element for the current elements. Thus we can put them into the answre list. let me try.

## 231. Power of Two

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2^x.

The basic idea is to divide n with 2 iterately unitl n == 1. And each iteration we will determine n % 2 == 0 or not. Thus, if finally n == 1, it means we can use 2*2...*2 to make a n. 

Follow up: Could you solve it without loops/recursion?

Because -2^31 <= n <= 2^31 - 1, we can use binary search! If 2^16 < target, it means k > 16. We will find a k until 2^k-1 < n, 2^k+1 > n. It satisfy the property of binary search. 

And an interesting thing - if we use n - 2*(n/2) != 0 to determine n % 2 == 0. Oh because if we use mod, we need to calculate the mod result of n % 2. But, if we use n - 2*(n/2) we only need to calculate one divide and one multipies. 

AC!