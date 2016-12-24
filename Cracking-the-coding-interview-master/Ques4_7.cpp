/* 4.7 Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. Avoidstoring additional nodes in a data structure.NOTE: This is not necessarily a binary search tree. */

#include <iostream>

using namespace std;

struct node{
	int data;
	node *right, *left;
};

void createMinimalBst(node* &root, int arr[], int start, int end)
{
	if (start>end)
		return;
	if (root==NULL)
	{
		node *ptr = new node;
		int ind = start + (end-start)/2;
		ptr->data = arr[ind];
		ptr->left = NULL;
		ptr ->right = NULL;
		root = ptr;
		createMinimalBst(root->left, arr, start, ind-1);
		createMinimalBst(root->right, arr, ind+1, end);
	}
}

bool isdecendent(node *root, node *root2)
{
	if (root == NULL)
		return false;
	if (root == root2)
		return true;
	return isdecendent(root->left, root2) || isdecendent(root->right, root2);
}

node* commonAnce(node* root, node* root1, node* node2)
{
	if (root == NULL)
		return NULL;
	if (root == root1 || root == root2)
		return root;
	bool root1_left = isdecendent(root->left, root1);
	bool root2_left = isdecendent(root->left, root2);
	if (root1_left && root2_left)
		return commonAnce(root->left, root1, root2);
	else if (root1_left || root2_left)
		return root;
	else
		return commonAnce(root->right, root1, root2);
}


int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	node* root;
	root = NULL;
	createMinimalBst(root, arr, 0, 8);
	node *ancestor = commonAnce(root, root->left->left, root->left->right->right);
	cout << ancestor->data;
}