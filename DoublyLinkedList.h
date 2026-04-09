#pragma once

struct DNode
{
	int value;
	DNode* next;
	DNode* previous;
	DNode(int v) : value(v), next(nullptr), prev(nullptr) {}
}

class DoublyLinkedList 
{
private:
	DNode* head;
	DNode* tail;

public:
	DoublyLinkedList();
	~DoublyLinkedList();

	void addAtBeginning(int v);
	void addAtEnd(int v);
	void addAtPos(int i, int v);
	DNode* find(int v)
};

