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

## 98. Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

* The left subtree of a node contains only nodes with keys less than the node's key.
* The right subtree of a node contains only nodes with keys greater than the node's key.
* Both the left and right subtrees must also be binary search trees.

Clearly, we can use recuesive way to check each subtree satisfy above condition or until we find a false condition.

Actually It do have some problem, the right value may be bigger than its root. Thus it shall still be smaller than it root. let me see how to solve this problem.

Thus, the principle is the maximal of its left tree shall be smaller than root value and minimal of minimal of right shall be smaller than the root. Thus each time we need to return the maximal and minimal each time. I need to learn how return multiple value in golang.

## 235. Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

I have done this question before. Just use BST to search it. If it's both left and right return true. Oh the optimization point is 'Because the query must exist' therefore, if the value is in its left, it means the value < left else the value > right. If both of them < root, then we need to search in root.left. If both of them > root, then we need to search in the root right. Other wise it means maximal > root and minimal < root we can return root directly. AC!

## 30. Substring with Concatenation of All Words

You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.

Interesting, this question seems not too hard. We can start from each index and too see if it can match the word in the dictionary.

Oh each word's size is the same. so the length will be words.size()*words[0].size()

Oh my solution tle, so the brute force cannot be accepted. OH, I found a std solution who use brute force and accpeted.  A tricky thing to do the iteration is: 1 - words[0].length is enough. Because we will use the slides window, And if we cannot find the word, we will give up this slides windows and restart from the next pos (right + word_len) And each possibilities is organized from 0 x 2x 3x 1 x + 1 => x 2x 3x. It's like a modular thing. So, we can only enumerate from 0 - x. And each time we move the winodws on this 0 x 2x 3x ....until we find the series window length equal to the words size. Very clear and great std code solution. Easy to understand.

## 126. Word Ladder II

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

* Every adjacent pair of words differs by a single letter.
* Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList. sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

I try to run my old program and I found that - memory out of limit.

Let me see the std's solution. The correct solution is still dfs. 

1. bfs to find how many steps we need to use the begin word to construct the other words through modifying one word.
2. dfs from the end words and each time to see if the modification words is return one step back in the dfs. And because we start dfs in the reverse order we need to do the dfs in the another order.

AC. not so hard, but we need to try some tricky way to do the optimizton - very hard to think!

## 13. Roman to Integer

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

* I can be placed before V (5) and X (10) to make 4 and 9. 
* X can be placed before L (50) and C (100) to make 40 and 90. 
* C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

Just use a iteration. And if next value is bigger than curernt one we will minus current one other wise we will add current one. AC!

## 387. First Unique Character in a String

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

I finished this question yesterday. just use a map to count. And do the iteration again until we find a cout equal to one. AC!

## 804. Unique Morse Code Words

International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:

'a' maps to ".-",
'b' maps to "-...",
'c' maps to "-.-.", and so on.
For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.

For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...". We will call such a concatenation the transformation of a word.
Return the number of different transformations among all words we have.

dict + transofrmation? use hashset to count the numebr of transfomration we have? let me try. AC!