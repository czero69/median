#include "stdafx.h"
#include "Heap.h"
#include <iostream>

inline
void swap(int &a, int &b)
{
	int aux = a;
	a = b;
	b = aux;
}

bool Greater(int a, int b)
{
	return a > b;
}

bool Smaller(int a, int b)
{
	return a < b;
}

Heap::Heap(int *b, bool(*c)(int, int)) : A(b), comp(c)
{
	heapSize = -1;
}


Heap::~Heap()
{
	if (A)
	{
		delete[] A;
	}
}

void Heap::siftUp(int i)
{
	int p = parent(i);

	// comp - differentiate MaxHeap and MinHeap
	// percolates up
	if (p >= 0 && comp(A[i], A[p]))
	{
		swap(A[i], A[p]);
		siftUp(p);
	}
}

void Heap::siftDown(int i)
{
	int lchild = left(i);
	int rchild = right(i);

	int tempchild;
	// comp - differentiate MaxHeap and MinHeap
	// greater(a,b) a > b for MaxHeap
	// smaller(a,b) a < b for MinHeap
	// percolates down

	if (lchild < MAX_HEAP_SIZE && rchild < MAX_HEAP_SIZE)
		tempchild = comp(A[lchild], A[rchild]) ? lchild : rchild;
	else if (lchild < MAX_HEAP_SIZE)
		tempchild = lchild;
	else if (rchild < MAX_HEAP_SIZE)
		tempchild = rchild;
	else
		tempchild = -1;

	if (tempchild > 0 && comp(A[tempchild], A[i]))
	{
		swap(A[i], A[tempchild]);
		siftDown(tempchild);
	}
}

int Heap::deleteTop()
{
	int del = -1;
	if (heapSize > -1)
	{
		del = A[0];

		swap(A[0], A[heapSize]);
		A[heapSize] = 0; // not necessary, just to keep out of boundary clean. this element is removed by index opertaion on heap size "--"
		heapSize--;
		siftDown(0);
	}

	return del;
}

bool Heap::insertHelper(int key)
{
	bool ret = false;

	if (heapSize < MAX_HEAP_SIZE)
	{
		ret = true;
		heapSize++;
		A[heapSize] = key;
		siftUp(heapSize);
	}

	return ret;
}

MaxHeap::MaxHeap() : Heap(new int[MAX_HEAP_SIZE], &Greater) { };
MaxHeap::~MaxHeap() {};

MinHeap::MinHeap() : Heap(new int[MAX_HEAP_SIZE], &Smaller) { };
MinHeap::~MinHeap() { };
