/* 4.8 You have two very large binary trees: Tl, with millions of nodes, and T2, with
hundreds of nodes. Create an algorithm to decideifT2 isa subtree ofTl.
A tree T2 is a subtree of Tl if there exists a node n in Tl such that the subtree ofn is identical to T2. That is, if you cut off the tree at node n, the two trees would be identical. */

#include <iostream>

using namespace std;

struct node{
	int data;
	node *right, *left;
};

void createMinimalBst(node* &root, int arr[], int start, int end)
{
	if (start > end)
		return;
	if (root==NULL)
	{
		node *ptr = new node;
		int ind = start + (end-start)/2;
		ptr->data = arr[ind];
		ptr->left =NULL;
		ptr ->right = NULL;
		root = ptr;
		createMinimalBst(root->left, arr, start, ind-1);
		createMinimalBst(root->right, arr, ind+1, end);
	}
}

bool isIdentical(node* root1, node* root2)
{
	if (root1 == NULL && root2 == NULL)
		return ture;
	if (root1 == NULL || root2 == NULL)
		return false;
	return isIdentical(root1->data == root2->data && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right));
}

bool isSubTree(node* root1, node* root2)
{
	if (root1 ==NULL && root2==NULL)
		return true;
	if (root1 ==NULL || root2 == NULL)
		return false;
	return (isIdentical(root1, root2) || isSubTree(node->left, root2) || isSubTree(node->right, root2);

}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};    // Bigger Tree
    int arr1[] = {1, 2, 3, 4};                  // Subtree
    node *root, *subRoot;
    root = subRoot = NULL;
    createMinimalBst(root, arr, 0, 8);
    createMinimalBst(subRoot, arr1, 0, 3);
    //cout<<isIdentical(root->left->left->left, subRoot->left);
    cout<<isSubTree(root, subRoot);
    return 0;
}