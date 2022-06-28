#include <iostream>
#include <vector>
using namespace std;

// /**
//  * Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		if (1 == preorder.size() && 1 == inorder.size())
		{
			return new TreeNode(preorder[0]);
		}
		else if (0 == preorder.size() || 0 == inorder.size())
		{
			return NULL;
		}

		TreeNode *node = new TreeNode(preorder[0]);
		int p = 1;
		int in = 0;
		for (int i = 0; i < preorder.size(); ++i)
		{
			if (preorder[p] == inorder[i])
			{
				node->left = new TreeNode(preorder[1]);
				p++;
			}
			else if (preorder[p] == inorder[i])
			{
				node->right = new TreeNode(preorder[p]);
				p++;
			}
		}
		return node;
	}
};

int main() {
	Solution sol;
	int a[5] = {3,9,20,15,7};
	int b[5] = {9,3,15,20,7};
	vector<int> preorder({3,9,20,15,7});
	vector<int> inorder({9,3,15,20,7});

	TreeNode *node = sol.buildTree(preorder, inorder);


	return 0;
};