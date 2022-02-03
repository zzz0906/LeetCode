##  Create Sorted Array through Instructions

Given an integer array instructions, you are asked to create a sorted array from the elements in instructions. You start with an empty container nums. For each element from left to right in instructions, insert it into nums. The cost of each insertion is the minimum of the following.

* The number of elements currently in nums that are strictly less than instructions[i].
* The number of elements currently in nums that are strictly greater than instructions[i].

it seems a simulation + an array to record some extra information?

1 <= instructions.length <= 105;1 <= instructions[i] <= 105.

binary search and find the most left equal place?

(log1+log2 + .. logn); nlogn => it's ok?

yes. I use std's python solution.

in python, there are bisec and bisec_left, one means all the elements in the left is less than current another is less or equal than current element.

```
bisect_left and bisect
```

Sorted Containers is an Apache2 licensed Python sorted collections library, written in pure-Python, and fast as C-extensions. The introduction is the best way to get started.

Sorted list values must be comparable. The total ordering of values must not change while they are stored in the sorted list.

Although I accpet this problem. But there are some places to optimize. For example, we find the left and right place, but we add this element. To use less code, we use sorted list's properties to add this element;

we use n*3log(n); but we can optimize it to n*(logn+some constant)

If I have more time today, I will write my owncode, using binary searching.

## Merge Sorted Array

two pointer?

i,j points to the start of the sorted array. Comparing the start place of the array and put them into a new array?

o(N+M)

oh...I know why the problem will give a larger nums1...you can compare the elements in reverse order. the bigger one in the end and in each turn! I am so idiot. 

## Add Two Numbers

A past problem before.

multiply strings or linked list. Just use a number to record the carry digits!

AC!

## Kth Largest Element in an Array

Just sort it and return the k-1... it's so easy.

## Count Sorted Vowel Strings

first, give me the length;

it's like a dp? we can record a,e,i,o,u's length then an is from a + e + i + o + u?

yes, ac...

## Path With Minimum Effort

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

DP again?

if we want to know i,j; we must come from i-1,j; i,j-1 i+1,j, i,j+1 four directions.

```
STD: dp[y][x] = min(max(dp[ty][tx], abs(h[ty][tx] – h[y][x]))) (x, y) and (tx, ty) are neighbors
repeat this process for at most rows * cols times.
if dp does not change after one round which means we found the optimal solution and can break earlier.
```

Therefore the core process of this problem is repeating cols*rows times!

Oh, it's a bellman-ford equation exactly. We can do at most rows*cols relax times! It's easy to think why should we do these process cols\*rows times.

Also, the std said that we can use dijkstra directly. Why I do not think about this algorithm!?


## Concatenation of Consecutive Binary Numbers

Basically, it let the behind one extend 10^n (n equals to the bits number.)

this problems has several hard points

* it's a reverse concat. For example, 123 is 1 10 11 the last one is 3. Threfore, if we use power to do the simulation, we should transfer 3 first, and get the end bit first.
* pay attention to the modular. In all time we shall do the modular. I forgot to do the modular in the sum to the final answer. Then RE...

AC!