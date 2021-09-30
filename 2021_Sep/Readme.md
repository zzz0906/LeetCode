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

## N-th Tribonacci Number

The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

Just do the iteration.

## Shortest Path in a Grid with Obstacles elimination

You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

DP [i][j][k] means we still have k chance to eliminate the obstacles?

DP[i][j][k] down, left, or right; DP[i-1][j][k], DP[i][j-1][k], DP[i-1][j-1][k] when i,j is not an obstacle. When i,j is an obstacle, it shall be DP[i-1][j][k + 1], DP[i][j-1][k + 1], DP[i-1][j-1][k + 1]

My method seems ok, but i use too much time to code it. Let me see the std.

the std use the bfs. First put the one step nodes in the queue. And if the one step go to a obstacles, we need to use the k. We use a i,j,k, visited array to record all the nodes + elimination choice we have used. We need to ensure, we will not go to the same node with the same choice we rest.

## Unique Email Addresses

Every valid email consists of a local name and a domain name, separated by the '@' sign. Besides lowercase letters, the email may contain one or more '.' or '+'.

* For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" is the domain name.
If you add periods '.' between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name. Note that this rule does not apply to domain names.

* For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.
If you add a plus '+' in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered. Note that this rule does not apply to domain names.

* For example, "m.y+name@email.com" will be forwarded to "my@email.com".
It is possible to use both of these rules at the same time.

Given an array of strings emails where we send one email to each email[i], return the number of different addresses that actually receive mails.

Just process all the mail and put them all into a hashmap?

AC.

## Sort Array By Parity II

Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

Return any answer array that satisfies this condition.

Follow Up: Could you solve it in-place?

so the hard part of the question is to sort it in-place.

2 4 6 8 10's places, we can only place the even number. We can do it in o(n).

so, we can still do quick sort in o(logn)? 1 2 3 4 5 6 => 2 4 6 8 12

left mid right, we need to compare their order. 

oh the problem do not let us to sort it...

how about using two pointers?

holy fuck...AC. But it's a long time for me to consider when shall move the next even number - numOfEven; the pos record the position of current position. We only move the numOfEven, when we have used this number it's

* nums[numOfEven] % 2 == 0 && numOfEven % 2 == 0 && numOfEven < pos
or
* num[numOfEven] % 2 != 0 we will let numOfEven++; when find another even, we will exchange numofeven and pos;

## Split Linked List in Parts

Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

just length / k and compute each part iterately? Then the (5/3) => 1.5

then we can spread 1 to each element.

but, how to do the spread; oh I know we can use a variable to record it/

Yes AC. And be careful with the size < k. Set each section as 1 and push the rest nullptr to the results vector.