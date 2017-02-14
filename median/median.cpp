// median.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Heap.h"
#include <iostream>

double getMedian(int e, double &m, Heap &l, Heap &r);
double Average(int a, int b);

int main()
{
	int A[] = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };
	//int A[] = { 0, 4, 3, 6, 1, 5, 2 };
	//int A[] = { 0, 1, 2, 3};
	int size = ARRAY_SIZE(A);
	double m = 0; // effective median

	Heap *left = new MaxHeap();
	Heap *right = new MinHeap();

	//@TODO warunki dla dw pierwszych
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
	std::cout << Average(A[0],A[1]) << std::endl;

	for (int i = 2; i < size; i++)
	{
		m = getMedian(A[i], m, *left, *right);
		std::cout << m << std::endl;
	}

	delete left;
	delete right;

	//windows terminal stop
	std::getchar();

    return 0;
}

double Average(int a, int b)
{
	return double(double(double(a) + double(b)) / 2.0);
}

// compheapsize function
// = 0 if - heaps size difference is less than 1
// = -1 if a < b - left contains less than one elements than right
// = 1 if a > b - left contains more than one elements than right
int compheapsize(int a, int b)
{
	//if (a == b)
	//	return 0;

	if (a > b + 1)
		return 1;
	else if (b > a + 1)
		return -1;
	else
		return 0;

	//return a < b ? -1 : 1;
}

double getMedian(int e, double &m, Heap &l, Heap &r)
{
	// Are heaps balanced? If yes, sig will be 0

	if (e < l.GetTop())
		l.Insert(e);
	else
		r.Insert(e);

	//std::cout << "numL: " << l.GetCount() << std::endl;
	//std::cout << "numR: " << r.GetCount() << std::endl;

	int sig = compheapsize(l.GetCount(), r.GetCount());
	switch (sig)
	{
	case 1: // There are more than one elements in left (max) heap
		r.Insert(l.ExtractTop());
		m = Average(l.GetTop(), r.GetTop()); 		// Both heaps are balanced
		break;
	case 0: // The left and right differs less than 1
		if (l.GetCount() > r.GetCount())
			m = double(l.GetTop());
		else if (l.GetCount() < r.GetCount())
			m = double(r.GetTop());
		else
			m = Average(l.GetTop(), r.GetTop());
		break;
	case -1: // There are more than one elements in right (min) heap
		l.Insert(r.ExtractTop());
		m = Average(l.GetTop(), r.GetTop());		// Both heaps are balanced
		break;
	}

	// No need to return, m already updated
	return m;
}