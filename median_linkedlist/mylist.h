#pragma once
#include <iostream>
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
using namespace std;

struct node
{
	int data;
	struct node* prev;
	struct node* next;
};

class Mylist
{
public:
	Mylist();
	~Mylist();
	void insert(int key);
	double getmedian();
	bool empty();

private:
	node* newnode(int d);
	int left, right;
	struct node* mid; //no head, no tail implementation. We don't need it.
	//Mylist() : mid(NULL), left(0), right(0) { *mid = NULL; }
};

inline Mylist::Mylist()
{
	this->left = 0;
	this->right = 0;
	mid = NULL;
}

inline Mylist::~Mylist()
{
	node* current = mid;
	bool skipfirst = false;
	while (current != NULL) {
		node* next = current->next;
		if(skipfirst) // skip it. It will be deleted in next loop
			delete current;
		skipfirst = true;
		current = next;
	}
	while (current != NULL) {
		node* prev = current->prev;
		delete current;
		current = prev;
	}
	mid = NULL;
}

inline node* Mylist::newnode(int d)
{
	node* p = (struct node*)malloc(sizeof(struct node));
	p->data = d;
	p->prev = NULL;
	p->next = NULL;
	return p;
}
inline double Mylist::getmedian() {
	if (left == right)
		return double((mid)->data);
	else
		return double((mid)->data + (mid)->next->data) / 2.0;
}

inline bool Mylist::empty()
{
	if (mid == NULL)
		return true;
	else
		return false;
}
inline void Mylist::insert(int key)
{
	if (this->empty())
	{
		(this->mid) = (newnode(key));
		return;
	}

	node* temp = mid;
	node* p = newnode(key);
	if (key<temp->data)
	{
		while (key<temp->data&&temp->prev != NULL)
		{
			temp = temp->prev;
		}
		if (key>temp->data)
		{
			p->next = temp->next;
			temp->next = p;
			p->prev = temp;
			p->next->prev = p;
		}
		else
		{
			temp->prev = p;
			p->next = temp;
		}
		(left)++;
		if ((left)>(right))
		{
			mid = (mid)->prev;
			(left)--;
			(right)++;
		}
	}
	else
	{
		while (key>temp->data && temp->next != NULL)
		{
			temp = temp->next;
		}
		if (key<temp->data)
		{

			p->prev = temp->prev;
			temp->prev = p;
			p->next = temp;
			p->prev->next = p;
		}
		else
		{
			temp->next = p;
			p->prev = temp;
		}
		(right)++;
		if ((left) + 1<(right))
		{
			mid = (mid)->next;
			(left)++;
			(right)--;
		}
	}
}