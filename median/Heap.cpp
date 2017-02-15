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

bool greater(int a, int b)
{
	return a > b;
}

bool smaller(int a, int b)
{
	return a < b;
}

// comp is an comparison function; it differs for MaxHeap and MinHeap
Heap::Heap(int *b, bool(*c)(int, int)) : A(b), comp(c)
{
	heapSize = 0;
}


Heap::~Heap()
{
	if (A)
	{
		//std::cout << "HS: " << this->getcount() << std::endl;
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

	if (lchild > 0 && rchild > 0)
		tempchild = comp(A[lchild], A[rchild]) ? lchild : rchild; //tempchild differs for MaxHeap and MeanHeap
	else if (lchild > 0)
		tempchild = lchild;
	else if (rchild > 0)
		tempchild = rchild;
	else
		tempchild = -1;

	if (tempchild > 0 && comp(A[tempchild], A[i])) // condition differs for MaxHeap and MeanHeap
	{
		swap(A[i], A[tempchild]);
		siftDown(tempchild);
	}
}

int Heap::deleteTop()
{
	int del = -1;
	if (heapSize > 0)
	{
		del = A[0];

		swap(A[0], A[heapSize - 1]);
		A[heapSize - 1] = 0; // not necessary, just to keep out of boundary value clean (eq to 0). this element is removed by index opertaion on heap size "--"
		heapSize--;
		siftDown(0);
	}

	return del;
}

bool Heap::insertHelper(int key)
{
	bool ret = false;

	if (heapSize <= MAX_HEAP_SIZE)
	{
		ret = true;
		heapSize++;
		A[heapSize-1] = key;
		siftUp(heapSize-1);
	}
	else
	{
		std::cout << "warning max heap size reached, insertion will be rejected..." << std::endl;
	}

	return ret;
}

MaxHeap::MaxHeap() : Heap(new int[MAX_HEAP_SIZE], &greater) { };
MaxHeap::~MaxHeap() {};

MinHeap::MinHeap() : Heap(new int[MAX_HEAP_SIZE], &smaller) { };
MinHeap::~MinHeap() { };
