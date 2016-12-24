/* 4.9 You are given a binary tree in which each node contains a value. Design an algo- rithm to print all paths which sum to a given value. Thepath does not need to start or end at the root or a leaf. */

#include <iostream>

using namespace std;

struct node {
	int data;
	node *right, node *left;
};

void creatMinimalBst(node* &root, int arr[], int start, int end)
{
	if (start>end)
		return;
	if (root == NULL)
	{
		node *ptr = new node;
		int ind = start + (end-start)/2;
		ptr->data = ptr[ind];
		ptr->left = NULL;
		ptr->right = NULL;
		root = ptr;
		creatMinimalBst(root->left, arr, start, ind-1);
		creatMinimalBst(root->right, arr, ind+1, end);
	}
}

void print(node *root, int sum, int *path, int level)
{
	if (root ==NULL)
		return;
	path[level]=root ->data;
	int s=0;
	for (int i=level; i>=0; i++)
	{
		s+=path[i];
		if (s==sum)
		{
			for (int j=level; j>=i; j--)
				cout << path[j]<< " ";
			cout << endl;
		}
	}
	if (root->left)
		print(root->left, sum, path, level+1);
	if (root->right)
		print(root->right, sum, path, level+1);
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	node *root;
	root = NULL;
	creatMinimalBst(root, arr, 0, 8);
	int path[100];
	print(root, 7, path, 0);
}