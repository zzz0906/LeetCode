## 1359. Count All Valid Pickup and Delivery Options

Given n orders, each order consist in pickup and delivery services. 

Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 

Since the answer may be too large, return it modulo 10^9 + 7.

Input: n = 2
Output: 6
Explanation: All possible orders: 
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.

I use the std directly. We have n delievelry task and n pickup task
& pn pickup task have to be before dn delively task

p1 d1

now let p1 p2 p3 ----- pn then we can get n permutaion of n pickup task which is n!

now if we add deleivery task Dn ( then it should be behind pn) and that the only position eligible for that. 1 Position

p1 p2 p3 ----- pn dn

but now where we can we put dn - 1

we can put dn - 1 at 3 positions at end , at before dn and behind pn-1
3 Position

Now for pn-2 there is dn - 2 and dn - 2 should be behind pn-2.

so if i take permutaion ,

pn-2 pn-1 dn-1 pn dn [so we can place dn-2 in 5 position according to this permutaion]

so 1 * 3 * 5 * (2n -1) kind of different permutaion we can have for difference places of order & deleivery task.

And at first, we have fix the permutation. We have n! permutation.

Overall, it's n! ( 1 * 3 * 5 * (2n -1) ).

Accept!


## 21. Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

We can use two pointer to point the current ListNode we iterate to. And put the smaller one to the res ListNode. And let the smaller pointer move one step. When one of the ListNode turn into empty, we can put the rest of the other to the answer ListNode.

## 