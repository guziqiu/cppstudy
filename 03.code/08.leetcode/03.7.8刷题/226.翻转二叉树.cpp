#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
TreeNode* invertTree(TreeNode* root) {
	// 终止条件
	if (nullptr == root) return nullptr;

	// 左子树翻转
	TreeNode *left = invertTree(root->left);
	// 右子树翻转
	TreeNode *right = invertTree(root->right);

	root->right = left;
	root->left = right;

	return root;
}
*/

TreeNode* invertTree(TreeNode* root) {
	if (nullptr == root) return nullptr;

	queue<TreeNode *> que;
	que.push(root);
	while (!que.empty()) {
		TreeNode *tmp = que.front();
		que.pop();

		TreeNode *left = tmp->left;
		tmp->left = tmp->right;
		tmp->right = tmp;
		if (nullptr != tmp->left) que.push(tmp->left);
		if (nullptr != tmp->right) que.push(tmp->right);
	}

	return root;
}

int main() {

	TreeNode *root = invertTree(new TreeNode(4, new TreeNode(2), new TreeNode(7)));
	cout << root->val << ", " << root->left->left << ", "<< root->right << endl;
	return 0;
}
