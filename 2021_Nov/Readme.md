## 130. Surrounded Regions

Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

[also done before](../Insights/130.md)

We know that if a O in the matrix contains a 'O', it must connect to the edge. The solution dfs from the edge position and turn all these O into $. And finally, this $ will turn into O and others will all be X!

YES. AC!

## 980. Unique Paths III

You are given an m x n integer array grid where grid[i][j] could be:

* 1 representing the starting square. There is exactly one starting square.
* 2 representing the ending square. There is exactly one ending square.
* 0 representing empty squares we can walk over.
* -1 representing obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

It's a DP problem? or a discrete mathematical problem? we can use all possible - the solution through the obstacle.

I also have done it before. Must every day problem before. 

OH, i know, we need to walk over every single block once. It's a pure brute force. We can assign the node we have been to as -1. And after dfs we restore it. And we store a pathcount and dfs them. Also, I use a zerocount to count all zero blocks. Only if the pathzerocount == zerocount, which mean we have been to all 0 blocks, then the answer count will add 1.

## 129. Sum Root to Leaf Numbers

[also done before](../Insights/129.md)

when we reach the leaf, add the number we accumulated.

## 404. Sum of Left Leaves

similar easy question. Just add the left child into the res.

## 441. Arranging Coins

You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

Find the maximum kk such that $\frac{k (k + 1)}{2} \le N$

$k = \sqrt{(2*N + \frac{1}{4})} - \frac{1}{2}$

AC.

## 260. Single Number III

Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

## 43. Multiply Strings

Why these days always show me the problem I have done before.

Just the Arbitrary-precision arithmetic again.

Start from the start position, use a integer to store the carry bit. Remember ignore the leading zero.

## 96. Unique Binary Search Trees

holy it's a mathematical question. [96](../Insigts/96.md)

It's like a DP question. Let's see the situation of 2

it has a left and non right and a right no left => dp[0]\*dp[1] + dp[1]\*dp[0]

for the situation of 3 we have 0,2 1,1 2,0 (the root take up 1 node) we have 2 nodes rest

Thus, we store the number of tree combinations in a dp array. And we take away a node as the root. 

It's actual a Catalan number. we cuase Catalan numbers can be expressed directly in terms of binomial coefficients by

$\pi_{k=2}^n \frac{n + k}{k}$

## 1178. Number of Valid Words for Each Puzzle

With respect to a given puzzle string, a word is valid if both the following conditions are satisfied:
word contains the first letter of puzzle.
For each letter in word, that letter is in puzzle.
For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage", while
invalid words are "beefed" (does not include 'a') and "based" (includes 's' which is not in the puzzle).
Return an array answer, where answer[i] is the number of words in the given word list words that is valid with respect to the puzzle puzzles[i].

brute force?

* 1 <= words.length <= 10^5
* 4 <= words[i].length <= 50
* 1 <= puzzles.length <= 104

puzzles[i].length == 7

words[i] and puzzles[i] consist of lowercase English letters.

Each puzzles[i] does not contain repeated characters.

Hashset?

First 1 <= words.length <= 10^5's contains the first words in puzzle or not? we need to do this process for each puzzle? 10^5*10^4 = 10^9 it's unaffordable. How can we solve this. Trie?

A constraint under 10 usually accepts a method with $N!$ time complexity with respect to this constraint. Factorial time complexities can occur for operations like finding all permutations from a set or using brute-force to solve the traveling salesman problem.

A constraint under 3030 usually accepts a method with $2^N$ time complexity at worst with respect to this constraint. Some examples include iterating over all combinations or subsets from a set or some brute-force solutions that use DFS.

Therefore, checking each word one by one will be too slow. Could we perhaps check multiple words at the same time?

The next problem is what kinds of words we want to put together?

So, our key can be a set containing what letters are in a word. Wait a minute, can we use a set as a key in a map?

When the number of distinct values that could be in a set is small (like 26 lowercase English letters), then we can transform each set into a number, using a very nice data structure called a bitmask (or bitset).

24 bits, each bits represent the numebr of alphabet exists or not.

Therefore, any word that does not contain the first letter in a puzzle cannot be valid for that puzzle. Thus, we only need to iterate over the subsets of letters contained in puzzle that also contain the first letter of puzzle.

We can iterate the subset of the puzzle. However, when working with a bitmask that represents a set of all possible items, we can use a simple trick to find all possible subsets of those items using only a for loop.

```
for (subset = bitmask; subsets >= 0; subset = (subset - 1) & bitmask) {
  // do what you want with the current subset...
}
```

Why does this work? The subsets must be included in range [0, bitmask], and if we iterate from bitmask to 0 one by one, we are guaranteed to visit the bitmask of every subset along the way.

But we can also meet those that are not a subset of bitmask. Fortunately, instead of decrementing subset by one at each iteration, we can use subset = (subset - 1) & bitmask to ensure that each subset only contains characters that exist in bitmask.

Also, we will not miss any subset because subset - 1 turns at most one 1 into 0.

    while subsets > = 0

        (subsets - 1) & bitmask

for one puzzle, the complexity is $O(2^{puzzle.length})$ which is much less than the total number of words in words.

o(10^4)*o(2^7) = 1.28\*10^7

## 122. Best Time to Buy and Sell Stock II

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

It's a greedy algorithm. yes. I think the most Reverso-Context part is the greedy. If we buy in the lower and sell it in a higher we can get the maximum profit. Because!!! If we have a higher in the future, we can buy and sell in the same day. Thus, if the price of future is higher, we still can buy it a day before and earn the profit. Thus, it's a greedy.

## 203. Remove Linked List Elements

## 739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

* 1 <= temperatures.length <= 105
* 30 <= temperatures[i] <= 100

For this question, it seems to ask to find a bigger value after. Can we do it reversely? The answer for a element will be the value > its and its position. yeap, it seems make sense. But how to do the insert operation. Which data structure is better. First the ds shall keep in order. And we can add an element. Multiset? let me try.

Oh, I think maybe we can use monotone queue? Because smaller value and far away value is meaningless, we only need the bigger one. And the element in monotone queue is the index. Let me try.

AC. Yes. This property is really important, we only need closer and bigger one. Which means, in our queue, we only keep it in the smaller -> bigger. And for the new one, it must be closer, so all the elements in the monotone queue who is smaller than the new one, shall out, they will never be the answer anymore.

## 1286. Iterator for Combination

Design the CombinationIterator class:

* CombinationIterator(string characters, int combinationLength) Initializes the object with a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
* next() Returns the next combination of length combinationLength in lexicographical order.
* hasNext() Returns true if and only if there exists a next combination.

dfs all results? 1 <= combinationLength <= characters.length <= 15

my dfs method is out of date. Use bitmask!

Total subsets possible for "abc" = 2^len("abc") = 2^3 = 8
Now bitmasks for all 8 subset are as follows:
Remember In bitmask, indexing goes from LSB to MSB i.e. from right to left.
For, eg: In string, "afgh" we have 'h' at 0th bit and 'g' at 1th bit, and so on till 'a' at 3rd bit.

* 000      ->      empty string      ->      Empty set (NOT added to our combinations set)
* 001      ->      "a"               ->      Length of string is 1 and combinationLength is 2, hence NOT added
* 010      ->      "b"               ->      Same as above
* 011      ->      "ba"              ->      Length of string = combinationsLength, hence ADDED to combinations set (In sorted order i.e. "ab")
* 100      ->      "c"               ->      Length of string is 1 and combinationLength is 2, hence NOT added
* 101      ->      "ca"              ->      Length of string = combinationsLength, hence ADDED to combinations set (In sorted order i.e. "ac")
* 110      ->      "cb"              ->      Length of string = combinationsLength, hence ADDED to combinations set (In sorted order i.e. "bc")
* 111      ->      "cba"             ->      Length of string is 3, but combinationsLength is 2 hence NOT added to combinations set

If we iterate these number, it will represent the string. However, for this problem, lexicographical order and no duplicate character. It means, we shall use set. And we can use bitmask for my set as above. And we only need to iterate all it number from 1 to 2^15.

Actually, I consider we can also use dfs for 2^15. For each position, we can do add or do not add to answer string. Overall, we will get a final answer. And we sort the string before. Through this way, we get a 2^15 solution.

## 62. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

A typical DP problem. f[i][j] = f[i-1][j] + f[i][j-1]; AC.

## 448. Find All Numbers Disappeared in an Array

Just put the value in the locations where its value is. 1 to 1, and all scan in the final time. If the index do not match value put them into the answer array.

## 540. Single Element in a Sorted Array

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

we have to perform binary search in the array. But how to move left or right? If each number appears twice, then it will be 11 22 33 44

and for the odd length n. down(n/2) -> means the middle, let me give an example

01 23 45 6 => single one in the right for 3

01 2 34 56 => single one in the left for 3

So, we can determine which one is the duplicate to decide to move to the next or right? let me try.

Also, we need to return the value.

And, for the final binary search iteration, we reach right and right + 1 as left. We still have to determine which one is single by their adjacent value and determine whether we reach the first and last index. Because it will do not have left or right value when we in the start and end.

## 106. Construct Binary Tree from Inorder and Postorder Traversal

[have done this problem before](../Insights/106.md).

we shall use post order to determine the split point. Because the inorder is left root right; postorder is left right root. Thus, we know the last one of postorder is root, this node's position in the inorder's left size is the size of left tree. We can extract this part to build a left tree recursively. The right tree shall be built in the same way. Thus, we can do it by split two vector and build tree recursively.

## 450. Delete Node in a BST

[also done before](../Insights/450.md)

we seem to find the node, and delete it. if it has children, then replace them with child, if child do not have children, we can only replace current one with its children and do not link the children.

my solution is to swap (delete value) with (the smallest value in its right tree.)

```
while (cur->left) cur = cur->left;
root->val = cur->val;
root->right = deleteNode(root->right, cur->val);
```