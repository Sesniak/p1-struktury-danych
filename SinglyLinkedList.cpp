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

void SinglyLinkedList::removeAtBeginning()
{
	Node* temp = head;
	head = head->next;

	if (!head)
	{
		tail = nullptr;
	}

	delete temp;
}

void SinglyLinkedList::removeAtEnd()
{
	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
		return;
	}
	Node* cur = head;
	while (cur->next != tail)
	{
		cur = cur->next;
	}

	delete tail;
	tail = cur;
	tail->next = nullptr;
}

void SinglyLinkedList::removeAtPos(int i)
{
	if (i == 0)
	{
		removeAtBeginning();
		return;
	}

	Node* cur = head;
	for (int k = 0; cur && k < i - 1; k++)
	{
		cur = cur->next;
	}
	if (!cur || !cur->next)
	{
		return;
	}
	Node* temp = cur->next;
	cur->next = temp->next;

	if (temp == tail)
	{
		tail = cur;
	}

	delete temp;
}

bool SinglyLinkedList::find(int v)
{
	Node* cur = head;
	while (cur)
	{
		if (cur->value == v)
		{
			return true;
		}
		cur = cur->next;
	}
	return false;
}
