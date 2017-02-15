## Finging effective median in running stream of integers

##Algorithm based on two heaps:

For the first two elements add smaller one to the maxHeap on the left, and bigger one to the minHeap on the right. Then process stream data one by one,

Step 1: Add next item to one of the heaps

   if next item is smaller than maxHeap root add it to maxHeap,
   else add it to minHeap

Step 2: Balance the heaps (after this step heaps will be either balanced or
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

O(n log(n))

After iterating half of the elements n/2
inserting/deleting is O(log n) for n elements in the heap at the worst case. doing it for n/2 elements gives O(n log n)

## second alghoritm linked list:
not implemented yet

Complexity:
O(n^2)
