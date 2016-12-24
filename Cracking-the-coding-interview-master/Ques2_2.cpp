/* 2.2 Implement an algorithm to find the kth to last element of a singly linked list.*/
/* solution: This algorithm recurses through the linked list. When it hits the end, the method passes
back a counter set to 0. Each parent call adds 1 to this counter. When the counter equals
k, we know we have reached the kth to last element of the linked list.*/

#include <string>
#include <iostream>
#include "LinkedList.h"

using namespace std;

Node* kLast(Node* head, int k)
{
	Node* current = head;

	int len = 0;
	while (current)
	{
		len++;
		current = current->next;
	}

	current = head;

	if (k > len || len < 1)
		return nullptr;

	int count = 0;
	while (len - count != k)
	{
		count++;
		current = current->next;
	}
	return current;

}