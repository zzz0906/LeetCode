## Maximum Depth of Binary Tree

104 which has been implemented! Easy...Just dfs

## Linked List Random Node

Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Just use a random to the range(0,N(lenght of the linked list)) and iterate to the kth(random number) linked list?

std also use my idea. OK!

## Increasing Order Search Tree

Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

just loop and store the father? I remember this similar problem.

BUT I still code wrong! Remember this solution!

```
while (cur || !q.empty()){
            while (cur){
                q.push_back(cur);
                cur = cur->left;
            } //keep searching left
            cur = q.pop_back();
            // push cur answer
            cur = cur->right; search the right
        }
```

## The kth Factor of n

1 <= k <= n <= 1000

find a factor keep count ++ unitl count = k? if we iterate to n, we still cannot find the kth then return -1?

AC...

## Populating Next Right Pointers in Each Node II

117 I have done it before!

Let me review it.

It's also a challenge problem.

It'a recursive problem actually. we need to let the right connect correctly first.

## Spiral Matrix II

I have done it before too...

59...Just simulate it.

## Pairs of Songs With Total Durations Divisible by 60

n^2?

and mod first? it seems easy.

N^2 tle...

1 <= time.length <= 6 * 104

oh! sort? and match each other in the order? 0,1,2...59? 59+1 58+2!

Yes AC!

## Binary Search Tree Iterator

I remember I have solved this problem before. Just use a stack to store all the order?

## Valid Mountain Array

Given an array of integers arr, return true if and only if it is a valid mountain array.

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < A[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

first increase then decrease.

Easy just record a flag for increase and decrease?

Yes but we need to pay attention to

1. only decrease with the same value (determine no increase)
2. only increase with the same value (determine no i-d's change)
3. the same value (determine arr[size-1] == arr[size-2])

AC!

## Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

I remember I use dfs + hashset?

Nope I have solved this problem before. leetcode 131

dfs to enumerate the start place of current string and choose the next start place

cur - next is a palindrome? then go to next round else go back to find the palindrome or return.

## Validate Binary Search Tree

It's easy question. Just to ensure all root's value shall < its whole left tree.

Also I find my original code is not correct and modify it.

## Decoded String at Index

An encoded string S is given.  To find and write the decoded string to a tape, the encoded string is read one character at a time and the following steps are taken:

If the character read is a letter, that letter is written onto the tape.
If the character read is a digit (say d), the entire current tape is repeatedly written d-1 more times in total.
Now for some encoded string S, and an index K, find and return the K-th letter (1 indexed) in the decoded string.

I seem to write a similar question for decoding a string in this way. when facing a string just repeat and add to answer? python's work!

I use simulate to this question! 

OH...I need to use mod or it will be TLE...

first I need to get the before length like

kkkk then we need to let it mode k

but how can i get the number of records?

oh...i do not read the problem carefully. a22 means (aa)2 not a*22. Also, a2b3 means (aab)3

oh...std only get the kth number.

we record current number length cnt when it's bigger than k then stop and find the kth.

and when facing a number we let cnt/number and k % number! because aa3 = 2*3 = 6 we let 6/3 first and then let k % 6/3 =  5%2 = 1 because we know k < length and we need to find the repeat one.

It's a hard problem and need us to think carefully.

##  Smallest Range II

Given an array A of integers, for each integer A[i] we need to choose either x = -K or x = K, and add x to A[i] (only once).

After this process, we have some array B.

Return the smallest(maximum value of B - minimum value of B).

we need to let maximum and minimum be close ASAP.

Greedy? 

I see std's solution.

this idea is genius!

* sort 
* we need to let minimum + k and maximum - k
* we need to divide the array to two part [0,i];[i,n]
* min and max in first part 0+k i+k and min and max in second part i-k,n-k

and we need to iterate i. it's o(nlogn)

## Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

just DO it recursively? 

yes determine abs|height1 - height2| <= 1 and its left and right. Then AC!

## Next Greater Element III

Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

abcddd

just move the bigger digits into the first place?

no...12443322 -> 13222344

The fisrt solution: 

like our idea. first, find the element in the tail that is greater than current value. If it's an ascending array, there is no solution. find it and swap the first element bigger than current value in the ascending array. Then, sort the value;

this is the way to get the next permutation!