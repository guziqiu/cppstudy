#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mirrorTree(TreeNode* root) {
	if (root == nullptr)
	{
		return root;
	}

	TreeNode *tmp = root->right;
	root->right = root->left;
	cout << root->right->left;
	root->left = tmp;
	cout << root->left->val << endl;
	root->left = mirrorTree(root->left);
	root->right = mirrorTree(root->left);

	return root;
}

void Print(TreeNode *node)
{
	if (node)
	{
		cout << node->val << ", ";
		// cout << node->left->val << ", ";
		// cout << node->right->val << ", ";
		Print(node->left);
		Print(node->right);
	}
	// if (node->left )

	return ;
}

int main() {
	TreeNode *root = new TreeNode(4);
	int arr[6] = {2,7,1,3,6,9};

	bool l = true;
	// TreeNode *head = root;
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	
	// cout << endl;
	Print(root);
	cout << endl;

	root = mirrorTree(root);

	Print(root);
	cout << endl;

	return 0;
}
