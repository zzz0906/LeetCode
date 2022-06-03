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
