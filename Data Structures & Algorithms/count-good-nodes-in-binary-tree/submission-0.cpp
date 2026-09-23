/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
	int dfs(TreeNode *root, int maxVal)
	{
		if (!root)
			return 0;
		int res = 0;

		if (root->val >= maxVal)
			return res = 1 + dfs(root->left, root->val) + dfs(root->right, root->val);
		else
			return res = dfs(root->left, maxVal) + dfs(root->right, maxVal);
		return res;
	}

	int goodNodes(TreeNode *root)
	{
		if (!root)
			return 0;
		int left = dfs(root->left, root->val);
		int right = dfs(root->right, root->val);
		return 1 + left + right;
	}
};
