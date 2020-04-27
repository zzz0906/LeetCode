# LeetCode Recording

Practicing my programming skill day by day
Record the consideration and analysis

## 10 Regular Expression Matching
~~Because it just contains '*', '.'.
I think we can detect if there are these two symbols in the pattern string. If there are not these two symbols we can just return whether these two strings are eaqual or not.~~

~~We use a **pointer** to point the position in s we want to compare. We use a **proced** variable to record the previous value for '*'.~~

~~If there is '*', that means we can fit a character with any times; then we repeat the pointer ++ until we cannot find the same one.~~

~~If there is '.', that means we can fit a random character. we can just add pointer;~~

~~If there is a albert, we need to compare it.~~

Then we can program the code in 10.cpp.

However
"aab"
"c*a*b"

Output
false

Expected
true

1. ~~We need to skip if we detect one character~~
2. ~~if the next char is '*' we need to skip too~~
3. ~~If we find all pattern but pointtos < s.length return false~~

Oh oh, it's not that easy; It's a **Recursion** or **Dynamic Programming** exercise. I refer to the **solution**:
I choose to use Recursion, let me figure it out

First if now position is '.' or a char then we can know that we just can match it with the string itself
we can if (p[now] != '*')
            return p[now] in {'.',s[point]} or match(pattern[now+1:],string[point+1:])

if the next position is a '*' 
So we can get zero pattern[now] then return match(pattern[now+2],string) or more than 1, therefore we can return match(pattern,sting[point+1:])

## 11 Container With Most Water

In this problem, it's easy to learn that we can just pick two points and calculate the answer (container water)

It's a n^2 solution.

Let me keep thinking, maybe we can just start from the middle? That's not correct.

Or we can start from the begin and end. Oh yes, we can.

if there is a better solution, we must move the point to the right left,if the value of the left or right is higher than ourselves. But how to calculate whether is better.

Then our complexity is n

We can just calculate the answer is (wide-1) * higer height or original height * (wide)

**BUT** Which point do we need to move? Right or Left?

Let me see, if the large on to move. we have no choice to make a better cotainer. Because the height is decided by the smaller one. and the wide become smaller (because of moving). So we need to move the smaller one. Then we can get the answer.


## 12 Interger to Roman
this is question for a integer that to a Roman
We can can just replace the data with related data.

If the number is < then a value then we should keep replace it. this is a typical replace question
Roman | value 
-----|-------
I	|1
IV	|4
V	|5
IX	|9
X	|10
XL	|40
L	|50
XC	|90
C	|100
CD	|400
D	|500
CM	|900
M	|1000
we can keep reduce until we cannot find a number that bigger than this number in the table.

## 15 3sum
if we just think about the brute force to find the three numbers, the time complexity is

N*(N-1)*(N-2)

It's too expensive. 
Let me think about sort first. Then we get a sorted array. We can just binary search it. (i,j,k)
if we fix an i, then we need to find a j and k, then we know that j + k = -i; we can find the k+i. we can use a bucket to store each value.

But you should pay attention to the existing of the value, Because the output cannot have the same value.

However fail, because it will have the probability to we choose a bucket and value is the same of value of the before value. that N^2 cannot be adapted.
________

Let use 3 pointers.j + k = -i if we point to i first, then we need to find the  j + k = -i if j + k > -i, this is a interesting question. the left + right is the most great sum. becuase the answer must between this two value. j....k. we must adjust the it between this two index. if (j + k) > -i k--; < -i then j++ until j == k;

this means the answer index must between the begin and end in the sorted array. 

## 16. 3Sum Closest
You have to find three number sum closet to the target offer, we can know that the we can use 15 problem

we need to answer close to the target. As the result, we can use a similar method as 15 to solve this problem. 
a+b+c = target a+b = target - c until find a most similar to the target. 

We keep using the o(n2) method to fix a value then find b and c. as the 15 describe.

## 18. 4sum
It more difficult to the last question.

Can we use last algorithms again? That's not true, we must use another algorithm. Because if we use above algorithm, the time complexity is too high.

However, similarly, we can use a+b = sum - (c+d) so we divide it to the 2 sum and 2 sum. Therefore, we can make a preprocess, first, we can add 2 numbers. for n numbers, we can get a C(n,2); pick 2 entity from the array. Then we choose to find a + b = target.

In this question, if I am a person, how to simulate I pick the 4 numbers. I can choose ith, jth (>i), choose k(>j), choose l (>k).

Then we can treat k,l like the 2 sum problem.

Therefore, it is a O(n^3). This is shown in 18std.cpp.

**Attention: Do not let the index out of the array, because leetcode will detect it, however our compiler do not **

However it TLE, we need to optimize it. I found that it's my programming problem, I use another guy's code in 18 std with the smae consideration. Then I pass this problem.

## 22 Generate Parentheses
it seems apparently, we choose a place to add the ();
the begin, inter and end, in this way we can get that:
xxxx
we can search all the answer however TLE...

It's a really simple question...we can just
add a left add a right, and keep the right > current left that's would be right. It's very fancy written style let me analysis it:

If we keep there must be a right < left
first ()
then (()), (()). If we can add a left first, then add the right > left
in the first we add ( -> (( -> ((())) (()(()) this way because we need to go back to find the next standard position

## 23 Merge k Sorted Lists

It's a little easy way, to choose a the min answer in all list, and let the chosen list start point ++;
And repeat until all list has be appended to the answer list.

I think the code is all right. However it show me stack buffer overflow. I need to debug it tomorrow.

However, it's not an efficient way to find the min.

We can maintain a heap to get the min. Each time we find the min, and add the head of the list to the heap each time.

I copy other's standard code in the 23_heap.cpp. (\ref https://blog.csdn.net/Ethan95/article/details/85195403)

I found my problem!!! I decide whether the answer is NULL

original code
```
if (answer == NULL){
                answer = tmp;
                head = answer;
            }else{
                answer->next = tmp;
                answer = answer->next;
            }
```

Code now
```
answer->next = tmp;
            answer = answer ->next;
            current[index] = current[index] -> next;
```

In the before code, I use a NULL to decide a pointer. I think maybe leetcode do not approve that behavior.

## 25 Reverse Nodes in k-Group

I think it is a easy question too. 

We only need to

1. FIRST we traverse the node list, we add the node to a new list N
2. Every time we run k times, we reverse the N add it to a new List ANSWER's tail.
3. We clear the list N. We repeat these operations until we reach the end of the node list.

The hardest part is part 3. We need to reverse the N. We need to reach the end, and scratch the end of the list. And do it again. Unitl there is no end.

Attention! if there is no more enough elements for reverse, then keep its original sequence.

We need to decide whether reverse first then decide whether reach the end (prevent the k is exactly the end.)

## 29 Divide Two Integers

It's easy to think about we use minus replacing the mutil.

7 / 3 = 7 - 3 - 3 
we minus, two "3", thus we know the answer is two.

Attention: please take care of negative numbers and Maximum value. (specially decide)

** Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows. **

I need to process overflow also if a huge number divide 1. we need to iterate the huge number times. It will be TLE. I need to find the STD answer.

I need to use BIT operations
The labs() function computes and returns the absolute value of the long integer argument, of the appropriate long integer type for the function. The llabs() function computes and returns the absolute value of long long integer argument.

if we can let divisor << 1 (*2) < dividend then divisor << 1;
So that we can know that, each time we use t*2, t^2*4, t^3*8 to compute the end of the answer. It's a consideration of quick power. and when we end, we know there is a 2^n;

Then we do it again, until we cannot find a more power number for the t.

## 30 Substring with Concatenation of All Words

We know that the we need to choose a substring for each index, st -> st + arbitrary length

However the words list is same length. Therefore, the arbitary length should be number of list * fixed length

Time complexity is O(n) n = length of s; Let do it.

If we only has one char, then TLE, GG.

We need to use another algorithm. 

We compare the each fixed length in the string using for loop instead of HashMap or Trie. I think this may be the problem of the TLE. It still TLE.
Let me keep optimize it tomorrow.

I use two optimization places:

    1. if substring size > end size just break;
    2. we use map assignment operations instead of add each words one by one.

Then the code has been accepted.

## 31. Next Permutation
If we want to understand this problem, we need to know what is permutation.
In wikipedia

`The word "permutation" also refers to the act or process of changing the linear order of an ordered set`

I wrote a python version in my freshman period. We find a discipline in this problem.

First, we find the diminishing sequence in the sequence. Then we reverse the diminishing sequence. And we have known a number before the diminishing sequence. We exchange this number with a number in the diminishing sequence (which is just a lttile bigger than this number, e.g. 3-4,4-5,5-6).

I just use the standard program to submit. Because it is just a regular program, I need to find the pattern or the discipline.

## 32 Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

It is a parentheses problem again. 

If we use dfs, we only need to add the left parenthesis, and choose if or if do not match right parenthesis. 

Can we use DP? I don't think so. I still cannot know how to decide whether there are Aftereffect.

I refer to the website 
https://www.cnblogs.com/grandyang/p/4424731.html

It's exactly a DP problem. 

Let DP represent the longest parenthesis length before i-1. therefore, the DP[i] can be calculated as length before this symbol.
1...i, we need to find the before symbol, DP[i-1]

if(s[i-1]=='(' || j<0 || s[j]==')') 
    dp[i] = 0;

the i - 1 - dp[i-1] represent the begin of max length of the parenthesis. i-2-dp[i-1]....i-2 i-1

Update formula:

dp[i] = dp[i-1] + 2 + dp[j]

## 33. Search in Rotated Sorted Array
Because the time complexity shall be logN, then I understand that we should use dichotomy. 

It remind me that there is only one point for rotating.
We can use dichotomy to find the unknow point first.

Then we can use dichotomy(binary search) to find the really number we need. 

I have this idea, but it is really hard to implement it. Then I refer to why do not mix two processes, finding the target and finding the rotation point.

If the mid value is less than end, then we can know the the mid to the end is in the ascending order. Then, if target is bigger than mid value, then we need to keep searching in the right. If the target is less than mid we must keep to search in the right.

If the mid value is bigger than the end, we know the begin (e.g, 3 4 5 6 0 1 2) then the right is in the ascending order. therefore if the target is less than the mid value, we need to search the target in the right part of the array. otherwise, we need to search in the left part of the array. 

## 34. Find First and Last Position of Element in Sorted Array

It's really easy if you are familiar with C++ STL. You can use lower_bound and upper_bound function.

!! There is some difference between the lower_bound, upper_bound and this problem. If we cannot find the target we shall ouput -1,-1 instead of the bound~

The upper_bound shall be modified in this problem. Let me finish it tomorrow.

I failed to use upper_bound, we still need to practice binary search.

Let me describe my idea. Let we think about a binary search. If the mid value < target, then we need to find in the right. > left. If equal, then we can record the index and return.

Then we have a index, we need to use while loop to extend to the left and right which is still equal to the target.

Attention to: not found the value and the vector is blank.

### 36. Valid Sudoku

Input is a vector with 2 dimensions. It's easy to use dfs. If we can fill each blank field with any number and each time we need to check the valid features. If we cannot find then return false; else return true;

It seems more easy than it looks. It just need to want to output the valid not to find the solutions.

It has 3 rules:
* Each row must contain the digits 1-9 without repetition.
* Each column must contain the digits 1-9 without repetition.
* Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

It's really easy. The difficult part of these 3 questions
is the question 3. how to iterate question 3 ? I choose to first choose (0,0) then (0,3) then (0,6) then (3,0)

### 37. Sudoku Solver

Lastday we need to determine whether the graph is valid or not. Today we need to find a solution.

**You may assume that the given Sudoku puzzle will have a single unique solution.**

therefore, we can use dfs, for a point (x,y) if it's '.' then we need to fill this empty space with a number in range of [0-9] and not appear in the row and column. Let us do it!

The relationship between 36 & 37 is really great. We can use 36's solution to decide whether the 37's current Sudoku problem is correct. If it's right, we can keep searching the next state. If it's wrong, we should return.

## 40. Combination Sum II

It seems like a DFS problem too. Let us user a dfs to find all the answer.

Or we can use Dynamic Programming. let mean DP[i] = how many combinations for number i.

then answer is DP[target].

We initialize the DP[each element of candidates] = 1

OH...OH, there are problems, we will repeat using the candidates. (e.g., 1+2 =3 DP[3] = 1 DP[1] = 1, howevery, the 3 consist of 1, we cannot use 3+1 to conduct 4.)

I still use dfs, then I am accepted...

I think there is a better way to solve this problem.

## 41. First Missing Positive
In this problem, we need to find the smallest missing positive integer in a Given an unsorted integer array.

I need to work in O(n) time and O(1) space. If we use hash function, the space is not O(1). 

**we can use bucket sort in the original array** What do this mean? We use the input vector to do this, we make a[i-1] = i
a[0] = 1 a[1] = 2....

But how can we put the corresponding numbers into the correct position? Well, we can swap it. If the number > length of the input vector, it certainly cannot be the order positive number. Thus, only it less than the n can be swap to the correct position.

**my own code report wrong answer however std is correct** why???

Because once swap is not enough. We need to keep swap until we cannot swap.

In the deep comprehension, the swap time complexity is to find each number correct position. So the time complexity is less than O(n).

**we need to determine whether a[i] > 0 first beacuse a[i] -1 can be overflow**

Done.

## 42. Trapping Rain Water

I think we can just use, for each point as the left wall we need to find the right wall.

And for the right wall we need take it as the left wall, then we repeat this process unitl we find the end of the array.

**attention!! if we do not find the great right wall, then we need let left wall ++ not let left wall be the right wall**

Oh..., if the there is a lower floor like, 3,1,1,3 then the real capacity is 3-1! So we need to let a variable to be the baseline.


Oh..., if the situation is 2 1 0 1 2 then the 1 and 1 will store 1 and 2 and 2 will store 3 therefore the answer is 3 + 1. we need to only calculate the same height.

That's not correct too. We need to flag the last time right wall. If this time we find is the same as the last right wall. we need to still calculate it.

If there are like 3 1 3, if we only calculate 1*(2-0) we need to calculate the (2-0)*(3-1)

Maybe we still need to use the original simulation ways. WALL DOWN UP (STOP HERE)DOWN

It not seems correct. We need to use another methods. Or, we can scan the array first then compare the left and right whihc one is higer. I am a little lazy. Let me keep finishing it tomorrow.

I gave up, this problem in my way, I need to write carefully. I think a more simple solution can make sense too.

OH...someone use stack, whose solution is basical as mine. The solution is genius!

we need to find the down up. and calculate once. Then we find the down up' left and right. Then it would be down up too? if it's we can calculate the rest part which not contain the middle down up. Therefore, we use stack.


## 43. Multiply Strings

It seems to return back to high school. We need to write a algorithm.

We need to use https://en.wikipedia.org/wiki/Sch%C3%B6nhage%E2%80%93Strassen_algorithm to compute the product of two numbers.

**please attention that the number we need to shift when we calculate the product by our hand.**

## 44. Wildcard Matching

It's a difficult question. I need to find a way to match the '?' and '*' characters
Maybe we can use dfs to solve '*' problems!

Yes we can. But, it's TLE. Let me think how to solve this problem tomorrow.

I work for my paper for a long time. Let me finish 44 today.
Wildcard the '*' can represent any number of char.

In the while iterations, if the char of s is equal to the char of p or '?'  then we shall move on. 

When we face a '*' in the pattern, we can use '*' to represent the unmatch character. However in dfs, we use all possible numbers to match the unmatch character. And in the std solution, we use '*' to find the less match. Therefore this match is minimal greedy.  

I find a situation that if the next char shall 
badac
*ac

OH!! I understand if the 'a' cannot match the first 'a', then we use * to match more characters. That's consideration is awesome!

```
while (i < m) {
    if (j < n && (s[i] == p[j] || p[j] == '?')) {
        ++i; ++j;
    } else if (j < n && p[j] == '*') {
        iStar = i;
        jStar = j++;
    } else if (iStar >= 0) {
        i = ++iStar;
        j = jStar + 1;
    } else return false;
}
```

## 45. Jump Game II

Oh, it's a classical problem I have met it too many times. I shall use DP. Let me think the DP state tranfer equation. 
f[i] = update by f[<i], so the steps before one point cannot influence the steps after this point.

TLE.....
IT's an interval cover problem?

[----]

[ ][----]
We can transfer this two jump interval to the

[---------]

It's a binary search to find the last reach point for this problem?

No I still need to search in the internet to find the standard solution.

It's can be implemented with greedy algorithm. 

In 45 cpp we need to scan all of the jump vector and for each jump vector we also need to find the entry of each jum vector. Thus, we only need to find the max of the now and save the scan time!!

In the above std algorithm, we only optimize the each time we do not update the i+a[i]

we only record in this time we can reach the farest point of our jump array.

## 46. Permutations

It's a regular question. However, it need to produce all permutations for the input. which means it's possible that sequence donot contain the original numbers.

Maybe we can permutate the index? Yes, accepted... the medium problem is indeed easy.