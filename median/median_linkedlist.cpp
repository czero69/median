#include <iostream>
#include "mylist.h"
#include "stdafx.h"

int main() {
	int A[] = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };
	struct mylist* mid = NULL;
	mid = newnode(A[0]);
	int left = 0;
	int right = 0;
	cout << mid->data << " ";
	for (int i = 1; i<12; i++)
	{
		insert(&mid, A[i], &left, &right);
		if (left == right)
			cout << mid->data << " ";
		else
			cout << (mid->data + mid->next->data) / 2 << " ";
	}

	std::getchar();

	return 0;
}