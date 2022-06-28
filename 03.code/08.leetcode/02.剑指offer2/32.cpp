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


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Solution {
// public:
    vector<vector<int> > levelOrder(TreeNode* root) {
		vector<vector<int> > ret;
		queue<TreeNode *> q;
		if (NULL != root) q.push(root);

		while (q.empty()) {
			size_t size = q.size();
			vector<int> v;
			for (int i = 0; i < size; ++i) {
				TreeNode *node = q.front();
				q.pop();

				v.push_back(node->val);
				if (NULL != node->left) q.push(node->left);
				if (NULL != node->right) q.push(node->right);
			}
			ret.push_back(v);
		}
		
		return ret;
    }
// };

int main() {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	vector<vector<int> > v = levelOrder(root);
	queue<TreeNode *> q;
	q.push(root);

	return 0;
}
