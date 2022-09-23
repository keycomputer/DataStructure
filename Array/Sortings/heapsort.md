A heap is a complete binary tree which is represented using array or sequential representation.

It is a special balanced  binary tree data structure where root node is compared with its children and arranged accordingly.Normally in max heap parent node is always has a value greater  then child node.

The  worst and  Average complexity of heap sort is O(n log2 n).


Algorithm of Heap Sort 
MAX-HEAPIFY(A,i)
    1- i<-left[i]
    2- r<-right[i]
    3- if l<heap-size[A]and A[l]>A[i]
    4- then largest<-1
    5- else largest<-i
    6- if r<heap-size[A] and A[r]>A[largest]
    7- then largest<-r
    8- if largest!=i
    9- then exchange A[i]<->A[largest]
    10- MAX-HEAPIFY[A,largest]

HEAP-SORT(A)
    1- BUILD-MAX-HEAP(A)
    2- for i<-length[A] down to 2
    3- do exchange A[1]<-> heap-size[A]-1
    4- heap-size[A]<-heap-size[A]-1
    5- MAX-HEAPIFY(A,1)

BUILD-MAX-HEAP(A)
    1- heap-size[A]<-length[A]
    2- for i<-(length[A]/2) down to 1 do
     3- MAX-HEAPIFY(A,i)

Implementation of Heap Sort 
As we know that heap sort is based on the tree structure. 

so we will take an example of heap sort with the based on tree.

Originally the given array is :[6,14,3,25,2,10,20,7,6]

First we call Build-max heap

heap size[A]=9

so,i=4 to 1, call MAX HEAPIFY (A,i)

i.e., first we call MAX HEAPIFY (A,4)

A[l]=7, A[i]=A[4] = 25,A[r] = 6

l<- left[4] = 8

r<-right[4] = 9

8<9 and 7>25 (false)

Then,largest <-4

9<9 and 6>25(false)

Then,largest = 4

A[i]<-> A[4]

Now call MAX HEAPIFY (A,2)

          6
    14          3
  25   2       10  20
7   6  
--------------------------
          6
    14          20
  25   2       10  3
7   6  
--------------------------
          6
    25          20
  14   2       10  3
7   6  
---------------------------
        25 
     6          20
  14   2       10  3
7   6  
-------------------

        25 
     14          20
  6    2       10  3
7   6  
-----------------------
        25 
     14          20
  7    2       10  3
6   6 

