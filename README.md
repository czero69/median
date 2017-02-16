# Finding effective median in running stream of integers

##Algorithm based on two heaps:

http://stackoverflow.com/questions/10657503/find-running-median-from-a-stream-of-integers

For the first two elements add smaller one to the maxHeap on the left, and bigger one to the minHeap on the right. Then process stream data one by one,

* Step 1: Add next item to one of the heaps

   if next item is smaller than maxHeap root add it to maxHeap,
   else add it to minHeap

* Step 2: Balance the heaps (after this step heaps will be either balanced or
   one of them will contain 1 more item)

   if number of elements in one of the heaps is greater than the other by
   more than 1, remove the root element from the one containing more elements and
   add to the other one

Then at any given time median is:
   If the heaps contain equal amount of elements;
     median = (root of maxHeap + root of minHeap)/2
   Else
     median = root of the heap with more elements
     
Complexity:
Θ(n log(n))

Insertion/removingroot is Θ(log(n))
(heap height is log2(N+1) for already inserted N values, where N=2^k-1, k is integer) 
insertions for N elements

inserting/deleting is Θ(log n) for n inserted elements. Doing it for n elements gives Θ(n log n)

## Alghoritm based on linked list:
- no head and tail, only middle pointer to Node
- 2 way linked list

Complexity:
Θ(n^2)

insertion is Θ(n)
worst case insertions for N elements. lim N->inf

##Math Θ(...)
- dla funkcji f() ścisle rosnącej
n*f(1) <= f(1)+f(2)+f(3)+..+f(n) <= n*f(n)
- jeśli jest to wielomian, współczynniki przy wyrazach wielomianu nie mają znaczenia (lim n-> inf)
