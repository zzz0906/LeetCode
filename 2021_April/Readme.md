## Stamping The Sequence

Interesting. It's covering problem. We have a string unit. We can paste it to the paper. The question is; if we want to construct a target. 

Also, if the sequence is possible to stamp, it is guaranteed it is possible to stamp within 10 * target.length moves.  Any answers specifying more than this number of moves will not be accepted.

I think this problem we only need to repeat pasting this process.

brute force? We must can find solutions... so if the character is not the same. we paste it again?


Oh my solution has problems. It can start anywhere

for example:

"abca","aabcaca"

we need to satisfy the last 'ca' first.

the std is so beautiful; How can I write these code? First, we stamp it. abca; then it turn to a****ca; attention, it means if we can paste **ca; then we can paste abca. So, we need to reverse our stamp order finally.

a***ca; then we try to reduce our stamp to \*bca; abc\*; we cannot generate ab\*a because if we want to paste it to the target then paste another original, next one must cover the a or other char.

## Palindrome Linked List

Done it befoere! 234!

## Global and Local Inversions

We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.

The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].

Return true if and only if the number of global inversions is equal to the number of local inversions.

simulation must be TLE.

we need to try other ways. 

It's a permutation. But this condition is hard to use.

today's thinking is over. I need to use more time. Fuck, the std also do not use permutations.

oh if the local inversions == global inversion, it means besides i+1 no other huge j.

we need to set a mininumber from i+2 - end; if the minimum > A[i], it means besides i + 1 there are some other values which are bigger than A[i].

But maybe this turn fail (Global > local) but in next turn local > Global? The std do not consider this situation? 

Accept but it has to proof that in each number global == local then overall global == local. proof: if these two values are not equal, oh fuck...

the local must < global. Becuase local is one of the global! so it's must be equal in each turn.