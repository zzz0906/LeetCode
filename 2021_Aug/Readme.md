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

if we turn some 0->1, we must transfer all the digits behind this position into 1.

But I fell it's a DP problem.

It's a DP, a reverse DP.

f[i,1] and f[i,0] means the number of steps we need to perform to let the [i-n] still be a Monotone Increasing when we turn i to 1 or 0;

thus, if s[i] == 1 f[i,1] = f[i+1,1] + 0; if s[i] == 0 f[i,1] = f[i+1,1] + 1

Thus, we can dp from end to start!

AC!

## Array of Doubled Pairs

Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.

We only need all 0 1 . 1 2 to have 2 times relationship. So it not transitive we only need 1 pair for the length 2 or 3 array. And 2 pairs for the length 4 or 5 array. So the question is asking the pair of 2 times relationship. so logn to find the *2 or /2 number exist or not. Nlong. Done! Let me implement it first.

oh fuck...this solution is wrong. for example 2 4 8 1. 2 shall match 1 instead of 4. but my algorithm will match 4.

let me see the std. oh std is the same as me? the use hashset instead of binary search.

we do not need to consider half pointer. Because we search from small to bigger.

yeh, hashset is better than binary search.

## Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

this is a really easy question.

we can use a dict as the key, and the value as the list for the words.

AC!

## Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

I remember I have done before. 

It's a greedy and unordered_map to record all the characters we need.

## Range Sum Query - Immutable

Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

303 also done before~

Just prefix sum.

## Count Good Nodes in Binary Tree

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

DFS and store the past maximum as a variable in the dfs. AC

## Decode Ways

91 has done before. DFS?

Yes, but we make recursion reversely, because the number at the behind do not contain more probability.

1. it's valid; the last one is zero, we cannot only select tmp[1]
2. it's valid the last one is not zero, we can still select tmp[1] and let tmp[0] belong to others
3. it's invalid, the last one is zero, we cannot deal with the zero, return 0
4. it's invalid, the last one is not zero, we can hope if we divid them in another can get a better result.


OH...fuck, I found I use DP before, not DFS...

The same idea as DFS...more simple.

## Maximum Product of Splitted Binary Tree

Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.

if we can get the sum in o(1)

This is a question I have done in Xiecheng's interviewer.

we need to enumerate all edges and get the sum in O(1)

If we know the sum of a subtree, the answer is max( (total_sum - subtree_sum) * subtree_sum) in each node.

Oh Xiecheng's interviewer need record the max of each tree. it's different. It doesn't satisfy the property of total - sub.

(sum - x)*x => maximum  (-x^2 + sum*x)' = -2x + sum*x

thus, when x = sum / 2, the function reach the maximum value.

* The number of nodes in the tree is in the range [2, 5 * 104].
* 1 <= Node.val <= 104

So the ans's maximum is (2.5*10^4*10^4)^2 = 9*10^16 < 2^64

yes ac!

## Rectangle Area II

We are given a list of (axis-aligned) rectangles. Each rectangle[i] = [xi1, yi1, xi2, yi2] , where (xi1, yi1) are the coordinates of the bottom-left corner, and (xi2, yi2) are the coordinates of the top-right corner of the ith rectangle.

Find the total area covered by all rectangles in the plane. Since the answer may be too large, return it modulo 109 + 7.

This is a little hard. How to calculate the share rectangles. In my view, compute area for each unit 1

oh, the std use my idea. calculate as the unit.

My idea is scanning from 1 to maximum wide as 1 unit, and Given the left and right, we know xi1, xi2 has a height yi1 yi2; we records a most height for each unit.

* 1 <= rectangles.length <= 200
* rectanges[i].length = 4
* 0 <= rectangles[i][j] <= 109
* The total area covered by all rectangles will never exceed 263 - 1 and thus will fit in a 64-bit signed integer.

We know, we can accumulate each are's sum for the height area. 

But here we can also use a n^2 to update each area. Like we records all left and right and height, if some has a new interval then we can update it. Oh, we can use interval tree to do this.

let me see the std's solution.

We can learn this idea to solve this kind of question. Use map to do it. map will sort it.we can push x axis as the key.
and the pair as value. pair's first value is height as the left and right. And 1 -1 means we have a start and ends and we push all the x's height into the same x asis's key's vector. Also, we will use count map to compute current x's height; 

for each x, we iterate all height for current x axis, we use a count to record the start and end; 1 + -1 => means we have a closure. We want to know current's height (It can be non continus;)

for x1 => 31 - 4-1 5-1 - 19 8-1 - 11

we can use a 1, -1 and count to iterate all height for current x to the next x;

Let me summarize it.

* a xis map for all the (height, count +1 , -1) pair
* heightcount map for the same x to sum all the non continus heights
* hegihtcount 's key is the height and value is the +1 ,-1 pair to compute the count. count is the +1 -1 for the start and end to construct the no-continus's height

## Two Sum IV - Input is a BST

Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

the same, fixed one number them find another number in the tree.

BFS for the tree and return the value? It's nlogn.

let me try using python.

AC!

## Complex Number Multiplication

A complex number can be represented as a string on the form "real+imaginaryi" where:

real is the real part and is an integer in the range [-100, 100].
imaginary is the imaginary part and is an integer in the range [-100, 100].
i^2 == -1.
Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.

just add their corresponding position's value?

(x1 + y1\*i)\*(x2 + y2\*i)

x1\*x1 - (y1\*y2) + (x1\*y2 + y1\*x2)i

yes AC!

## Sum of Square Numbers

Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

o(n) is not possible. a\*a + b\*b = c

oh we can iterate ans in sqrt(c)

because if two numbers are both greater than sqrt c than a^2 + b^2 > 2c

or sqrt(c/2) if both greater than c/2; than we have > c

thus we need to enumerate one value from 1 to sqrt(c/2)

yes AC.

## Range Addition II

You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.

Count and return the number of maximum integers in the matrix after performing all the operations.

first we only let the right down corner's upper matrix be incremented. Thus, it's easily to think the same value must be in the same left upper matrix.

* 1 <= m, n <= 4 * 104
* 0 <= ops.length <= 104
* ops[i].length == 2
* 1 <= ai <= m
* 1 <= bi <= n

each operation will perform let same value be different with others not in the upper left matrix

for example [2,1] and [0,3]

oh the problem as me the maximum number not most common number

so the answer must be the most upper left matrix. So we only need to return the minimum number of each.

## Find Minimum in Rotated Sorted Array

Question I have also done before. We still can use binary search for this question.

6 7 0 1 2 3 4 5

bigger smaller bigger so if it's still less than middle one, then left and bigger than middle one and less than start it must in the right. else in the left

oh, it just need us to find the minimum one. I wrote a o(n) before.

let me update to logn using binary search.

if middle > right, means the start point in the right interval, just let left = mid + 1