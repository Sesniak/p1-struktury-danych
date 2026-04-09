#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() : head(nullptr), tail(nullptr) {}

SinglyLinkedList::~SinglyLinkedList()
{
	Node* cur = head;
	while (cur)
	{
		Node* next = cur->next;
		delete cur;
		cur = next;
	}
}

void SinglyLinkedList::addAtBeginning(int v)
{
	Node* n = new Node(v);
	n->next = head;
	head = n;
	if (!tail) tail = n;
}

void SinglyLinkedList::addAtEnd(int v)
{
	Node* n = new Node(v);
	if (!head)
	{
		head = tail = n;
	}
	else
	{
		tail->next = n;
		tail = n;
	}
}

void SinglyLinkedList::addAtPos(int i, int v)
{
	if (i == 0)
	{
		addAtBeginning(v);
		return;
	}
	Node* cur = head;
	for (int k = 0; cur && k < i - 1; i++)
	{
		cur = cur->next;
	}
	if (!cur)
	{
		return;
	}
	Node* n = new Node(v);
	n->next = cur->next;
	cur->next = n;
	if (!n->next)
	{
		tail = n;
	}
}

Node* SinglyLinkedList::find(int v)
{
	Node* cur = head;
	while (cur)
	{
		if (cur->value == v)
		{
			return;
		}
		cur = cur->next;
	}
	return nullptr;
}
