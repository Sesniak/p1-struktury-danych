#pragma once

struct Node 
{
	int value;
	Node* next;
	Node(int v) : value(v), next(nullptr) {}
};

class SinglyLinkedList 
{
private:
	Node* head;
	Node* tail;
public:
	SinglyLinkedList();
	~SinglyLinkedList();

	void addAtBeginning(int v);
	void addAtEnd(int v);
	void addAtPos(int i, int v);

	void removeAtBeginning();
	void removeAtEnd();
	void removeAtPos(int i);

	bool find(int v)
};