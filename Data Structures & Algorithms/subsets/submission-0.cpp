class Solution
{
public:
	vector<vector<int>> res;
	int dfs(int i, vector<int> &subSet, vector<int> &nums)
	{
		if (i >= nums.size())
		{
			res.push_back(subSet);
			return 0;
		}
		subSet.push_back(nums[i]);
		dfs(i + 1, subSet, nums);
		subSet.pop_back();
		dfs(i + 1, subSet, nums);
	}

	vector<vector<int>> subsets(vector<int> &nums)
	{
		vector<int> subSet;
		dfs(0, subSet, nums);
		return res;
	}
};
