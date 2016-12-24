/*2.3 Implement an algorithm to delete a node in the middle of a singly linked list, given
only access to that node*/

#include <string>
#include <iostream>
#include "LinkedList.h"

using namespace std;

bool removeNode(Node* node)
{
	if (node == NULL || node->next == NULL)
		return false;

	//update and delete
	Node* temp = node->next;
	node->data = temp->data;
	node->next = temp->next;
	delete temp;

	return true;
}