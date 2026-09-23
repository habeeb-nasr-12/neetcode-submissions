class Solution
{
public:
	bool isVaild(TreeNode *root, int minVal, int maxVal)
	{
		if (!root)
			return true;
		if (!(minVal < root->val && maxVal > root->val))
			return false;

		return isVaild(root->left, minVal, root->val) &&
			   isVaild(root->right, root->val, maxVal);
	}
	bool isValidBST(TreeNode *root)
	{
		if (!root)
			return true;
		return isVaild(root, INT_MIN, INT_MAX);
	}
};
