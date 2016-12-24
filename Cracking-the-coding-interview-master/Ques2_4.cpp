/*2.4 Write code to partition a linked list around a value x, such that all nodes less than x
come before alt nodes greater than or equal to x.*/
/* solution: elements, we can actually create two different linked lists: one for elements less than x,
and one for elements greater than or equal to x.
We iterate through the linked list, inserting elements into our before list or our after
list. Once we reach the end of the linked list and have completed this splitting, we
merge the two lists */

#include <string>
#include <iostream>
#include "LinkedList.h"

using namespace std;

// runs in O(n) time with O(n) space
// there are various ways to do this, but I end up deleting the original list
// and returning the merged lower and upper value lists

Node* part(Node* head, int val)
{
	if (head == NULL)
		return nullptr;
	LinkedList* bigger = new LinkedList();
	LinkedList* lower = new LinkedList();
	Node* current = head;

	while (current)
	{
		if (current->data < val)
			lower->insert(current->data);
		else
			bigger->insert(current->data);
		current = current->next;
	}

	// reset current back to the head
	//current = lower->head;
	Node* temp = lower->head;

	while (temp->next)
		temp = temp->next;
	temp->next = bigger->head;

	return temp;
}