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
	unordered_map<int, int> inorderMap;

	TreeNode *buidTreeNodes(vector<int> &preorder, int preStart, int preEnd,
							vector<int> &inorder, int inStart, int inEnd)
	{
		if (preStart > preEnd || inStart > inEnd)
			return nullptr;
		TreeNode *root = new TreeNode(preorder[preStart]);
		int rootIndex = inorderMap[root->val];
		int leftSize = rootIndex - inStart;
		root->left = buidTreeNodes(preorder, preStart + 1, preStart + leftSize, inorder, inStart, rootIndex - 1);
		root->right = buidTreeNodes(preorder, preStart + leftSize + 1, preEnd, inorder, rootIndex + 1, inEnd);
		return root;
	}

public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		for (int i = 0; i < inorder.size(); i++)
		{
			inorderMap[inorder[i]] = i;
		}
		return buidTreeNodes(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
};