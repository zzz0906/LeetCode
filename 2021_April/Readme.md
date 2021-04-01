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

