#pragma once

#define MAX_HEAP_SIZE (128)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

class Heap
{
public:
	// Initializes heap array and comparator required
	// in heapification
	Heap(int *b, bool(*c)(int, int));
	// Frees up dynamic memory
	virtual ~Heap();

	// We need only these four interfaces of Heap ADT
	bool Insert(int key)
	{
		return insertHelper(key);
	}
	int GetTop()
	{
		return top();
	}
	int ExtractTop()
	{
		return deleteTop();
	}
	int GetCount()
	{
		return count();
	}

protected:

	// We are also using location 0 of array
	int left(int i)
	{
		if (2 * i + 1 > heapSize)
			return MAX_HEAP_SIZE + 1;
		else
			return 2 * i + 1;
	}

	int right(int i)
	{
		if (2 * (i + 1) > heapSize)
			return MAX_HEAP_SIZE+1;
		else
			return 2 * (i + 1);
	}

	int parent(int i)
	{
		if (i <= 0)
		{
			return -1;
		}
		return (i - 1) / 2;
	}

	// Heap array
	int *A;
	// Comparator
	bool(*comp)(int, int);
	// Heap size
	int heapSize;

	// Returns top element of heap data structure
	int top(void)
	{
		int max = -1;

		if (heapSize >= 0)
		{
			max = A[0];
		}
		return max;
	}

	// Returns number of elements in heap
	int count()
	{
		return heapSize + 1;
	}

	// Heapification
	// Note that, for the current median tracing problem
	// we need to heapify only towards root, always
	void siftUp(int i);
	void siftDown(int i);

	// Deletes root of heap
	int deleteTop();

	// Helper to insert key into Heap
	bool insertHelper(int key);
};

class MaxHeap : public Heap
{
private:
public:
	MaxHeap();
	~MaxHeap();
};

// Specilization of Heap to define MinHeap
class MinHeap : public Heap
{
private:
public:
	MinHeap();
	~MinHeap();
};