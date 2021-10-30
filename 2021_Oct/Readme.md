## Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

typical DP. f[i,j] means the maximum common subsequence before i and j. Thus, DP[i][j] will come from DP[i-1][j-1] + 1 or DP[i][j-1], DP[i-1][j] 's maximum

AC!

## 201. Bitwise AND of Numbers Range

I have submitted this problem before, just remember if the length diff is bigger than 1, which means that the beginning of the bit form is 1&0 = 0; it must have corss a total diff form because it carry a number to the head.[100 - 1000]

## 543. Diameter of Binary Tree

we can dfs two path for a node. And store the length1 + length2 as a path. And compare the path to the answer. We only store the maximum answer which shall be diameter.

yes, ac!

## 374. Guess Number Higher or Lower

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns 3 possible results:

-1: The number I picked is lower than your guess (i.e. pick < num).
1: The number I picked is higher than your guess (i.e. pick > num).
0: The number I picked is equal to your guess (i.e. pick == num).

Return the number that I picked.

I also have done before. just binary search.

## 1008. Construct Binary Search Tree from Preorder Traversal

Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right

so given a A....[smaller than A] we cecusive call smaller than A and take them as the left tree of A.

let's do this.

AC

## 279. Perfect Squares

279. done before!

## 309

also done before... DP

DP record current money. And use buy,sold,rest to do the DP. I thnik this question is hard.

buy[i] means we bought a stock before ith day's maximum profit.

sell[i] means we sold a stock before ith day's maximum profit.

rest[i] means we are coll down in ith day's maximum profit.

buy[i]  = max(rest[i-1] - price, buy[i-1]), sell[i] = max(buy[i-1] + price, sell[i-1]), rest[i] = max(sell[i-1], buy[i-1], rest[i-1])

## 123. Best Time to Buy and Sell Stock III

still do it before. it's still a dp. 

* l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
* g[i][j] = max(l[i][j], g[i - 1][j]);

## 437. Path Sum III

Finished it before. Why all the problems are done before in these three days? Strange...

make a array to record father's sum and count how many elements that add current value eqaul to target. Also, do not forget zero add current value.

## 993. Cousins in Binary Tree

Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

I found hard to return the depth from the dfs

we can use a `pass by value` to solve this problem and compare them in a same dfs.

## 496. Next Greater Element I

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

we can use a map to do the o(n) tiem complexity?

nope, we still need to iterate the following index after current to find the next big one.

let me see the std's solution. oh, it's the same.

## 151. Reverse Words in a String

we can reverse the whole string first, And reverse each word separately (determined by the space).

s.reverse

and we use for loop, if we find a space, we need to do the reverse for the word because we reverse the whole string before.

```
while (start < s.length && end < s.lengt()){
    while (s[start] == ' ') start++;
    end = start;
    while (s[end] != ' ') end++;
    end -= 1;
    reverse(s.begin() + start, s.begin() + end);
}
```

AC!

## 380. Insert Delete GetRandom O(1)

Implement the RandomizedSet class:

* RandomizedSet() Initializes the RandomizedSet object.
* bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
* bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
* int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.

we use a unordered_map to map integer to index. because there is no duplicates. We can delete it by swap the last one with the one we want to delete (value->index o(1) swap o(1) delete the last one in vector o(1))

AC!

## 451. Sort Characters By Frequency

I have done it before!

just use a hashmap to do count the number

## 222. Count Complete Tree Nodes

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

I think my past ans is std. It's so celever. It only go the most left and right. If the length is equal, it means it's complete and we can compute by pow(2,N).

## 155. Min Stack

This problem is tricky. We can use two stacks to do this. we use another stack to record current minimum and push it into the stack. we know that for a element, if its upper (stack's upper) is greater than it, if we want to get minimum, these values are meaningless. Because if we want to pop, these upper values are out of the stack first. And we the minimum must be the element instead of these upper values. Thus, for another stack, we only push the value less than the top value.

## 226. Invert Binary Tree

Given the root of a binary tree, invert the tree, and return its root.

Just swap these two child. And do this process recursively.

## 75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

we can use double pointer. Because we only need to push 0 to the head and 2 to the end. Thus, we can store the position of red and blue we have stored.

AC.

## 15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

sort the array. And enumerate the first number. And use two pointer, one from small to big and another from big to small. Thus, we can move if its sum is bigger, move the bigger one to smaller one, etc. => n^2. AC.

## 994. Rotting Oranges

You are given an m x n grid where each cell can have one of three values:

* 0 representing an empty cell,
* 1 representing a fresh orange, or
* 2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

BFS? We can add a step to store the step we bfs here. The step variable is like a timestamp. And we only store the minimum one. Overall, it's a mn algorithm. If next one's timestamp is smaller, we won't bfs to it, because this update is meaningless. And return the final step. The start point is all the rotten orange. we find the maximum value.

AC!

## 1044. Longest Duplicate Substring

Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.

Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".

* 2 <= s.length <= $3 * 10^4$
* s consists of lowercase English letters.

Trie tree? Maybe we can add a count. But we have to get all substring. It's o(n^2), we have to use 6*10^8. That's impossible. I guess it's a string algorithm, like state machine. can we use double pointer?

yes, KMP + binary search as the correct algorithm. And the correct algorithm is Rabin–Karp. RK encode each substring as a hash value. for example, 'bcd' will store as $1*26^2 + 2*26 + 3$ And we use a slides window to store all the maximum duplaces string. And after that, if we want to move the windows, we have to minus the last first character value =  last character related number * 2^window_length. And times rest values 26, and add the new value. We have to find whether there is a duplicates value.

I have a question, whether it satisfies the condition to use binary search. Actually, we can use binary search. Because if there is no duplicates for length n, we cannot find more longer length string. If we can, which means there is a length-n substring of these two duplicates string, it's a contradiction.

Overall, we can use binary search. And time complexity is o(loglength * length) complexity.

Pay attention to this: we want to move the windows, we have to minus the last first character value, we have to minus a value, thus it may be a negative value when we use modular. Therefore, we need to add m and % m again. Oh, even we use this hash method, it‘s still possible to be different with the same value. For example, abz == aca. 

Great question.