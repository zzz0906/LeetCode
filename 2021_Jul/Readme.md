## Gray Code

89! Done before

recursive. 1's gray code is come from two bit.

And, the wikipedia's solution. 

Also, >>'s priority is bigger than ^

oh, so the before it's >> 1 and use ^ to multiply it.

So, the i^i>>1 means two neiborhood shall not be both 1 in binary code! this is the definition of gray code too.

00 00

01 01

11 10

10 11

## Find K Closest Elements

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

* |a - x| < |b - x|, or
* |a - x| == |b - x| and a < b

let me think sort it and binary search? nlogn?

1 <= arr.length <= 104

yep. AC!

let me see the std.

oh...the array is sorted. we can use binary search directly. we can delete n-k number that start from head and tail...brillant!

## Max Sum of Rectangle No Larger Than K

363 I have done before. Let me review it.

The std use binary search and prefix sum to solve this problem. 

In my view again, the std solution use two iterator to enumerate the rows.

From i-j; can we find the number of columns which

1. First iterate the left, then right of a rectangle i-j
2. Then, we have i - j; in this step, we calculate the prefix sum of each rom in sum array. Because we need to iterate the index j, we can calculate in each iteration.
3. We need to enumerate the column index j. Pay attention to here, we can use two sum's idea. we can iterate from 1 - m row; we want to know the i - j == k? thus, we can do this, k - [1-j] = target, and we need to find the target in the [1-j] and the target will be the lower_bound!

So interesting problem.

##  Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Classical DP problem right?

f[i] represents the maximum length of including current element.

f[i] <- f[j] + 1 whose v[j] < v[i]; n ^ 2;

Then the minimum problem can be optimized to nlogn. 

<!-- And we can use some idea of montonic queue  -->

<!-- we know that, the element whose value > current value but length <= current value, this element is meaningless. then we can use binary search to find the corresponding maximum length value. -->

## Find Median from Data Stream

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

oh, this median is not the binary search. 

just preserve the order of the array. priority queue

each time use binary search to insert; but insert time cannot be o(1);

if we use priority queue; the complexity is o(n/2);

skip list? or the binary tree. but we need it to be balanced, otherwise its complexity is o(n);we need to record the number of the subtree.

oh multiset's cbegin is constant begin and we need to use advanced to perform ++ operation.

more efficient solution than the obvious one is to keep a persistent iterator to the middle element and update it whenever you insert/delete items from the set. 

let me try advanced first.

AC!

the std use big and small heap. the big heap store the left, and sort it from minimum to maximum. and small heap store the maximum to minimum. thus, the answer is the minimum of the left + the maximum of the right. genius idea!

## Isomorphic Strings

205 done before. Just use a map->vector to record all the characters' positions. Easy.

## Custom Sort String

order and str are strings composed of lowercase letters. In order, no letter occurs more than once.

order was sorted in some custom order previously. We want to permute the characters of str so that they match the order that order was sorted. More specifically, if x occurs before y in order, then x should occur before y in the returned string.

Return any permutation of str (as a string) that satisfies this property.

order has length at most 26, and no character is repeated in order.

str has length at most 200.

order and str consist of lowercase letters only.

we can just count the number of char in the string. and output following the order string and add the extra string.

O(N); Easy.

## Valid Triangle Number

Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

for each numbre, we need to the number of numbers < current value and in the left of current value as k;

also we can get the number of numbers whose values are larger than current value and are in the right of current value. We name this number as j;

the answer is j*k for each value. 

1 <= nums.length <= 1000
0 <= nums[i] <= 1000

we know 0 <= nums[i] <= 1000; we can use two bucket to do above left and right things.

First, we can from left to right, and put each value in a bucket while record a prefix sum. For example, 1,3,3,7,9

bucket : 1: 1 prefix sum: 1: 1

bucket : 1: 1 3: 1 prefix sum: 1: 1 3: 2 prefix sum 

for a number k; the answer will be the (left prefix sum - bucket itself )*(right prefix sum - bucket itself)

the complexity is o(n)

oh godd secnario!

## 4Sum 

18\. I have done before. 

just use a n^3 is ok...? 

## Partition Array into Disjoint Intervals

Given an array nums, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.

left and right are non-empty.

left has the smallest possible size.

Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

we can take the left's maximum as a value, and right's minimum as a value, and we perform removing and inserting. Thus, it's a heap alike data structure?

5 0 3; 8 6; two priority list can solve this problem. better idea?

if we restrict the left array, the only things we need to do is to find the maximum in the right; when the array all the value is the descend in the right, and all less the right value,  the complexity will reach o(n^2).

or, we can use a idea like prefix sum. We can use a array to record the maximum and minimum

yes! AC! 

## Binary Tree Pruning

Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

A subtree of a node node is node plus every node that is a descendant of node.

DFS the tree, and take return value as each tree's subtree contain 1. if anyone of subtree do not cotain 1, just delete it, or not link it.

AC!

## Convert Sorted Array to Binary Search Tree

108 I have done before.

I think we can just cut from middle?

```
a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Tha's means we need to split in the middle and let left as the left tree and right as the right tree.

We can use recursive again! Yes! AC!
```

I use a trick that use the iterator to build a vecotr.