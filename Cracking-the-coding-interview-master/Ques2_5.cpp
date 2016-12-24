/* 2.5 You have two numbers represented by a linked list, where each node contains a
single digit. The digits are stored in reverse order, such that the 1 's digit is at the head
of the list. Write a function that adds the two numbers and returns the sum as a
linked list.*/

/*implementation runs in O(n) time with O(1) space by overwriting one of the
original lists. It is an iterative implementation that handles numbers of
different lengths.
for part B (if the lists are in forward order) simply reversing the list
in O(n) time and running the same algorithm does the trick
*/
/*didnt get it very well*/
#include <string>
#include <iostream>
#include "LinkedList.h"

using namespace std;

//calculate the length of list
int lenList(Node* head)
{
	Node* temp = head;
	int len = 0;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return len;
}

void padlist(Node* list, int pad)
{
	int count = 0;
	Node* temp = list;
	//go to the end
	while (temp->next)
		temp = temp->next;
	while (count != pad)
	{
		temp->next = new Node();
		temp = temp->next;
		temp->data = 0;
		temp->next = nullptr;
		count++;
	}
}

Node* reverse(Node* head)
{
	if (head == NULL)
	{
		return nullptr;
	}

	Node* previous = nullptr;

	while (head)
	{
		Node* temp = head->next;
		head->next = previous;
		previous = head;
		head = temp;
	}

	head = previous;

	return head;

}
void sumlink(Node* list1, Node* list2)
{
	if (list1 == NULL && list2 == NULL)
		return;
	Node* l1 = list1;
	Node* l2 = list2;
	// determine if a list is longer and if so, pad that list
	int len1 = lenList(l1);
	int len2 = lenList(l2);

	if (len1 > len2)
		padlist(l2, len1 - len2);
	else
		padlist(l1, len2 - len1);

	int carry = 0;
	int val = 0;
	while (l1 || l2)
	{
		l1->data += carry;

		val = l1->data + l2->data;

		if (val > 9)
		{
			carry = 1;
			val = val - 10;
		}
		else
		{
			carry = 0;
		}

		l1->data = val;

		l1 = l1->next;
		l2 = l2->next;
	}

	
	// if the final digit had a carry we need to add one to the end
	if (carry)
	{
		// reset the head and find the last element
		l1 = list1;
		while (l1->next)
		{
			l1 = l1->next;
		}

		l1->next = new Node();
		l1->next->data = 1;
		l1->next->next = nullptr;
	}
}