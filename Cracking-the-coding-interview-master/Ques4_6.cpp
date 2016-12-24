/* 4.6 Write an algorithm to find the 'next'node (i.e., in-order successor) of a given node in
a binary search tree. You may assume that each node has a link to its parent.*/

#include <iostream>
#include <stack>

using namespace std;

struct node {
	int data;
	node *right, *left;
};

void createMini(node* &root, int arr[], int start, int end)
{
	if (start > end)
		return;
	if (root ==NULL)
	{
		node *ptr = new node;
		int ind = start + (end-start)/2;
		ptr->data = arr[ind];
		ptr->left = NULL;
		ptr->right = NULL;
		root = ptr;
		createMini(root->left, arr, start, ind-1);
		createMini(root->right, arr, ind+1, end);
	}
}

node* inorderSucc(node* root, int k)
{
	stack<node*> s;
	node *ptr = root;
	bool searched = false;
	while (true)
	{
		while (ptr)
		{
			s.push(ptr);
			ptr = ptr->left;
		}
		if (s.empty())
			break;
		ptr = s.top();
		s.pop();
		if (searched)
			return ptr;
		if (ptr->data == k)
			searched = true;
		ptr = ptr->right;

	}
	return false;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	node* root;
	root = NULL;
	createMini(root, arr, 0, 8);
	node* searchnode = inorderSucc(root, 4);
	cout << searchnode->data << endl;
}
