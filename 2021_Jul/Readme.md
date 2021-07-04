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