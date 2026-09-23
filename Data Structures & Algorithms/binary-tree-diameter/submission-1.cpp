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
	int findDiameter(TreeNode *root, int &res)
	{
		if (!root)
			return 0;
		int left = findDiameter(root->left, res);
		int right = findDiameter(root->right, res);
		res = max(res, left + right);

		return 1 + max(left, right);
	}
	int diameterOfBinaryTree(TreeNode *root)
	{
		if (!root)
			return 0;
		int res = 0;
		findDiameter(root, res);
		return res;
	}
};
