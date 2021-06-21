## Swim in Rising Water
On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

We need to determine whether we can dfs to the end-point

the minimum value across all the path from the end to the start!

Shall I use DP for mrore efficient purpose. But the direction is four, we still can move right and left. 

Oh...DFS TLE.

The std use bfs. start from a value and bfs and add them all into the queue.

BUT!!! I think most efficient way is still binary search. 

The method of using a number and unordered_set to perform the node we have been to is really pretty.