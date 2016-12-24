#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
	this->head = nullptr;
}

LinkedList::~LinkedList()
{
	Node* cur = head;
	while (cur != 0)
	{
		Node* next = cur->next;
		delete cur;
		cur = next;
	}
	head = nullptr;
}

void LinkedList::insert(int val)
{
	if (head == NULL)
	{
		head = new Node();
		tail = head;
		head->next = nullptr;
		head->data = val;
	}
	else
	{
		tail->next = new Node();
		tail = tail->next;
		tail->data = val;
		tail->next = nullptr;
	}
		
}

void LinkedList::createCycle()
{
	tail->next = head->next;
}

void LinkedList::display()
{
	Node* temp;
	if (head == NULL)
		return;
	temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << ' ';
		temp = temp->next;
	}
	std::cout << std::endl;
}