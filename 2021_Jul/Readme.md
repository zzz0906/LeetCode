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
