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