## Number of Recent Calls

Easy question. Just I don't know what the question ask me to do. Just to find the the number of requests in the [t-3000; t]

I cannot use bucket because we cannot allocate a 10^9 array.

the t is increasing; which means we can push out the t-3000's value which cannot be accessed ever.

## Rotate List

Same as 61 which I have done before


## Binary Search

lower_bound? ...

It seems so easy.

YES ac... if lower_bound find it then return lower_bound index else return -1;

This problem help me with reviewing the c++ stl.

## Serialize and Deserialize BST

An open question. How to transfer BST to a string. Just like the 0 1 2 3 4 5 with index and each one has a value like

value,

JUST BFS & DFS... It's not a great question.

THE std use #val #left #right... format. It great

I want to change it to a array and then transfer it to a string. 

It seems in order traverse is the easiest way.

It's very hard to consider using input and output stream!

learn it!

## Minimum Number of Arrows to Burst Balloons

I read this question twice to understand what this question want to express. The ballon is around [x1,x2] you need to shot a point in the [x1,x2] then you can burst this ballon.

Some ballon is overlay you can shot one to busrt multiple.

-2^31 <= xstart < xend <= 2^31 - 1

This problem is to find the interval's intersection!

[[1,2],[2,3],[3,4],[4,5]]

2,3,4

when we shot 2,4 then we can burst all. Oh, DP?

Nope...I take the std's idea. 
First for the minimum ballon, it start has no overlap. which means 1,2 2,3 3,4 4,5 we can just shot 1,2 and we must shot it. Then, for an iterval. We must shot it. then it has a the end and the ballon whose start is less than its end can be shot either. 

But **after that**, we need to update end. because maybe there are situations start start end end then we want to shoot both two ballons, we need to let the shot point in the start-min(end,end).

HOLY!! two dimensions array can be sorted directly!

YES...it use recursive to compare two one-dimension array in two dimension array...


