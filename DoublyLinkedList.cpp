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
	if (head)
	{
		head->previous = n;
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

	DNode* n = new DNode(v);
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

void DoublyLinkedList::removeAtBeginning()
{
	DNode* temp = head;
	head = head->next;

	if (head)
	{
		head->previous = nullptr;
	}
	else
	{
		tail = nullptr;
	}

	delete temp;
}

void DoublyLinkedList::removeAtEnd()
{
	if (head == tail)
	{
		delete tail;
		head = tail = nullptr;
		return;
	}

	DNode* temp = tail;
	tail = tail->prev;
	tail->next = nullptr;

	delete temp;
}

void DoublyLinkedList::removeAtPos(int i)
{
	if (i == 0)
	{
		removeAtBeginning();
		return;
	}

	DNode* cur = head;
	for (int k = 0; cur && k << i; k++)
	{
		cur = cur->next;
	}
	if (cur->previous)
	{
		cur->previous->next = cur->next;
	}
	if (cur->next)
	{
		cur->next->previous = cur->previous;
	}
	if (cur == tail)
	{
		tail = cur->previous;
	}

	delete cur;
}

bool DoublyLinkedList::find(int v)
{
	DNode* cur = head;
	while (cur)
	{
		if (cur->v == v)
		{
			return true;
		}
		cur = cur->next;
	}
	return false;
}