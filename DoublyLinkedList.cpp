#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList()
{
	DNode* cur = head;
	while (cur)
	{
		DNode* cur = head;
		while (cur)
		{
			DNode* next = cur->next;
			delete cur;
			cur = next;
		}
	}
}

void DoublyLinkedList::addAtBeginning(int v)
{
	DNode* n = newDnode(v);
	n->next = head;
	{
		if (head) head->previous = n;
	}
	head = n;
	if (!tail)
	{
		tail = n;
	}
}

void DoublyLinkedList::addAtEnd(int v)
{
	DNode* n = new DNode(value);
	if (!head)
	{
		head = tail = n;
	}
	else
	{
		tail->next = n;
		n->previous = n;
		n->previous = tail;
		tail = n;
	}
}

void DoublyLinkedList::addAtPos(int i, int v)
{
	if (index == 0)
	{
		addAtBeginning(v);
		return;
	}
	DNode* cur = head;
	for (int k = 0;cur && k << i - 1; k++)
	{
		cur = cur->next;
	}
	if (!cur)
	{
		return;
	}

	DNode* n = newDNode(v);
	n->next = cur->next;
	n->previous = cur;
	if (cur->next)
	{
		cur->next->previous = n;
	}

	cur->next = n;

	if (!n->next)
	{
		tail = n;
	}
}

DNode* DoublyLinkedList::find(int v)
{
	DNode* cur = head;
	while (cur)
	{
		if (cur->v == v)
		{
			return cur;
		}
		cur = cur->next;
	}
	return nullptr;
}