/*Write code to remove duplicates from an unsorted linked list*/
#include <string>
#include <iostream>
#include <unordered_map>
#include "LinkedList.h"

using namespace std;
//uses undordered_map run time is O(n) with O(n) space
void removeD(Node* head)
{
	if (head == NULL)
		return;
	unordered_map<int, bool> map;
	Node* current = head;
	map[current->data] = 1;
	while (current->next)
	{
		if (map[current->next->data] == 0)
		{
			map[current->next->data] = 1;
			current = current->next;
		}
		else
		{
			Node* temp = current->next;
			current->next = current->next->next;
			delete temp; 
		}
	}

}

//uses no additional data structure run time is O(n^2) with O(1) space
void removeD2(Node* head)
{
	if (head == NULL)
		return;
	Node* current = head;
	Node* runner;

	while (current)
	{
		runner = current;
		while (runner->next)
		{
			if (current->data == runner->next->data)
			{
				Node* temp = runner->next;
				runner->next = current->next->next;
				delete temp;
			}
			else
				runner = runner->next;
		}
	}
	current = current->next;
}


int main()
{
	LinkedList* myList = new LinkedList();
	myList->insert(5);
	myList->insert(7);
	myList->insert(12);
	myList->insert(7);
	myList->insert(16);
	myList->insert(16);
	myList->insert(25);
	myList->insert(11);
	myList->insert(5);

	myList->display();

	removeD(myList->head);
	myList->display();
	delete myList;

	return 0;
}
/*
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {};
};

bool isDup(ListNode *cur, ListNode *p)
{
	while (p != nullptr && p != cur)
	{
		if (p->val == cur->val)
			return true;
		p = p->next;
	}
	return false;
}

ListNode *removeDuplicate(ListNode *head)
{
	if (head == nullptr || head->next == nullptr) return head;
	ListNode *p, *cur = head->next, *pre = head;
	while (cur != nullptr)
	{
		if (isDup(cur, head))
		{
			pre->next = cur->next;
			cur = cur->next;
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
	return head;
}

int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(2);
	ListNode *p = removeDuplicate(head);
	for (; p != nullptr; p = p->next) cout << p->val << "->";
	cout << "NULL" << endl;
	return 0;
}
*/