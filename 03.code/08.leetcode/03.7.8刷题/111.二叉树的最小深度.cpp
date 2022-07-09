#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int minDepth(TreeNode* root) {
	// 深度优先 O(N)
	if (nullptr == root) return 0;

	if (root->left == nullptr && root->right == nullptr) {
		return 1;
	}
	int min_depth = INT32_MAX;

	if (nullptr != root->left) {
		min_depth = min(minDepth(root->left), min_depth);
	}

	if (nullptr != root->right) {
		min_depth = min(minDepth(root->right), min_depth);
	}

	return min_depth  + 1;
}

int minDepth(TreeNode* root) {
	if (nullptr == root) return 0;

	std::queue<std::pair<TreeNode *, int>> que;
	que.push(make_pair(root, 1));

	while (!que.empty()) {
		TreeNode *node = que.front().first;
		int depth = que.front().second;
		que.pop();

		if (nullptr == node->left && nullptr == node->right) {
			return depth;
		}

		if (nullptr != node->left) {
			que.push(node->left, depth + 1);
		}

		id (nullptr != node->right) {
			que.push(node->right, depth + 1);
		}
	}

	return 0;
}
int main() {
	// cout << min_depth << endl;

	return 0;
}
