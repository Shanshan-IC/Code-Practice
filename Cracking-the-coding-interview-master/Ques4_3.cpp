/* 4.3 Given a sorted (increasing order) array with unique integer elements, write an algorithm
to create a binary search tree with minimal height. */

/* solution: To create a tree of minimal height, we need to match the number of nodes in the left
subtree to the number of nodes in the right subtree as much as possible. This means
that we want the root to be the middle of the array, since this would mean that half the
elements would be less than the root and half would be greater than it. */

#include <iostream>

using namespace std;

struct node {
	int data;
	node *right, *left;
};

void createBST(node* &root, int arr[], int start, int end)
{
	if (start > end)
		return;
	if (root == NULL)
	{
		node *temp = new node;
		int ind = start + (end - start)/2;
		temp->data = arr[ind];
		temp ->left = NULL;
		temp->right = NULL;
		root = temp;
		createBST(root->left, arr, start, ind-1);
		createBST(root->right, arr, ind+1, end);
	}
}

int main()
{
	int arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	node* root;
	root = NULL;
	createBST(root, arr, 0, 8);
	cout << root->left->data << " " << root->data << " " << root ->right->data << endl;
}