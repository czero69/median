// median.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Heap.h"
#include <iostream>

double getMedian(int e, double &m, Heap &l, Heap &r);
double average(int a, int b);

int main()
{
	//int A[] = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };
	int A[] = { 0, 4, 3, 6, 1, 5, 6 };
	//int A[] = { 1, 2 ,3 ,9 , 9, 9, 9, 9};
	int size = ARRAY_SIZE(A);
	double m = 0; // effective median
	
	Heap *left = new MaxHeap();
	Heap *right = new MinHeap();

	int greaterF, smallerF;

	if (size > 1)
	{
	greaterF = A[0] >= A[1] ? A[0] : A[1];
	smallerF = A[0] < A[1] ? A[0] : A[1];
	left->Insert(smallerF);
	right->Insert(greaterF);
	}

	if(size > 0)
	std::cout << A[0] << std::endl;
	if(size > 1)
	std::cout << average(A[0],A[1]) << std::endl;

	// from 3rd element to size
	for (int i = 2; i < size; i++)
	{
		if (i < MAX_HEAP_SIZE)
		{
			m = getMedian(A[i], m, *left, *right);
			std::cout << m << std::endl;
		}
		if (i == MAX_HEAP_SIZE)
		{
			std::cout << "error: Max_Heap_Size is reached..." << std::endl;
			break;
		}
	}

	delete left;
	delete right;

	//windows terminal stop
	std::getchar();

    return 0;
}

double average(int a, int b)
{
	return double(a + b) / 2.0;
}

// compheapsize function
// = 0 if - heaps size difference is less than 1
// = -1 if a < b - left contains less than one elements than right
// = 1 if a > b - left contains more than one elements than right
int compheapsize(int a, int b)
{
	if (a > b + 1)
		return 1;
	else if (b > a + 1)
		return -1;
	else
		return 0;
}

double getMedian(int e, double &m, Heap &l, Heap &r)
{
	if (e < l.gettop())
		l.Insert(e);
	else
		r.Insert(e);

	//std::cout << "numL: " << l.GetCount() << std::endl;
	//std::cout << "numR: " << r.GetCount() << std::endl;

	int sig = compheapsize(l.getcount(), r.getcount());
	switch (sig)
	{
	case 1: // There are more than one elements in left (max) heap
		r.Insert(l.extractTop());
		m = average(l.gettop(), r.gettop()); 		// Both heaps are equal size
		break;
	case 0: // The left and right differs no more than 1
		if (l.getcount() > r.getcount())
			m = double(l.gettop());
		else if (l.getcount() < r.getcount())
			m = double(r.gettop());
		else
			m = average(l.gettop(), r.gettop());
		break;
	case -1: // There are more than one elements in right (min) heap
		l.Insert(r.extractTop());
		m = average(l.gettop(), r.gettop());		// Both heaps are equal size
		break;
	}

	// No need to return, m already updated
	return m;
}