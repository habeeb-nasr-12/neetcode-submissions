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
	int findMaxSum(TreeNode *root, int &res)
	{
		if (!root)
			return 0;
		int leftSide = max(findMaxSum(root->left, res), 0);
		int rightSide = max(findMaxSum(root->right, res), 0);

		 res = max(res, root->val + leftSide + rightSide);

		return root->val + max(leftSide, rightSide);
	}
	int maxPathSum(TreeNode *root)
	{
		int res = root->val;
		findMaxSum(root, res);
		return res;
	}
};
