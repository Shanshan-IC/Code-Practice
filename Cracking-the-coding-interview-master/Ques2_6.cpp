/* 2.6 Given a circular linked list, implement an algorithm which returns the node at the
beginning of the loop.*/

#include <string>
#include <iostream>
#include "LinkedList.h"

using namespace std;

Node* findCycle(Node* head)
{
	if (head == NULL)
		return nullptr;

	//step 1: find whether the cycle exists
	Node* slow = head;
	Node* fast = head;

	int diff = 0;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)//collision
			break;
	}

	if (fast == NULL || fast->next == NULL)
		return nullptr;

	// slow is set to the head and then both are moved at the same pace
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}