## 1480. Running Sum of 1d Array

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

## 867. Transpose Matrix

Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

Just use a new matrix and i,j = j,i. Done!

## 304. Range Sum Query 2D - Immutable

Here, we try to use prefix sum for each line.

Can we use a 2-d prefix sum?

left upper's sum for each element == i-1,j + j-1,i - i-1,j-1

yep, I found a std using this idea. AC!

## 52. N-Queens II

he n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

I have done this problem before. Just use a dfs and each time try to place a queen in the 2d array. When placing a queen, we make all its row column diagonal as inpossible to put the queen until we put n queens or no where to put the queen. Also we need to care about the duplicate solution. AC!

## 160. Intersection of Two Linked Lists

Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

Note that the linked lists must retain their original structure after the function returns.

Custom Judge:

The inputs to the judge are given as follows (your program is not given these inputs):

intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.

* listA - The first linked list.
* listB - The second linked list.
* skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
* skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.

The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.

This question is really trick. We can think about it in this way. When way iterate it throught this order. Assume k1, k2 is the length of before intersection's linked list. Thus, if we put these two linked list a1,a2 as 

a1->a2

a2->a1

We will have

k1 -> m -> k2->m

k2 -> m -> k1->m

We can see that if we iterate these two linked list, after iterating k1 m k2 and k2 m k1 we will have the same length iteration and reach the same intersection. AC!! If no intersection they will be equal as a == b == nil. AC!

Also, in golang, both struct and struct pointer shall use . to indicate attribute.