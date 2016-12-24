/* 2.7 Implement a function to check if a linked list is a palindrome,*/
//Runs in O(n) time with O(n) space

#include <string>
#include <iostream>
#include "LinkedList.h"

using namespace std;

Node* reserve(Node* head)
{
	if (head == NULL)
		return nullptr;
	Node* temp = nullptr;
	while (head)
	{
		Node* temp2 = head->next;
		head->next = temp;
		temp = head;
		head = temp;
	}
	head = temp;
	return head;
}

bool isPalindrome(Node* head)
{
	Node* temp = head;
	LinkedList* rev = new LinkedList();
	int len = 0;
	int count = 0;
	while (temp)
	{
		rev->insert(temp->data);
		temp = temp->next;
		len++;
	}

	temp = head;
	//reverse the list
	rev->head = reserve(rev->head);
	Node* revHead = rev->head;
	// now compare the two but only up to half way
	while (count != len / 2)
	{
		if (revHead->data != temp->data)
			return false;
		revHead = revHead->next;
		temp = temp->next;
		count++;
	}
	return true;
}