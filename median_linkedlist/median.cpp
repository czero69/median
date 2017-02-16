#include <iostream>
#include "mylist.h"

int main() {
	//int A[] = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };
	int A[] = { 0, 2, 6, 4, 3 };
	int size = ARRAY_SIZE(A);
	Mylist *list = new Mylist();
	for (int i = 0; i<size; i++)
	{
		list->insert(A[i]);
		cout << list->getmedian() << " ";
	}

	std::getchar();

	return 0;
}