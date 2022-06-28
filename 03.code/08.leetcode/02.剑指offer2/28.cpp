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

// bool check(TreeNode *p, TreeNode *q)
// {
// 	if (!p && !q) return true;
// 	else if (!p || !q) return false;
// 	return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
// }

// TreeNode* mirrorTree(TreeNode* root) {

// 	return check(root, root);
// }


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool check(TreeNode *p, TreeNode *q)
{
	queue<TreeNode *> que;
	que.push(p);
	que.push(q);
	while (!que.empty())
	{
		
	}



	// return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
}

bool isSymmetric(TreeNode* root) 
{
	// queue<TreeNode *> q;

	return check(root, root);
}


int main() {


	return 0;
}
