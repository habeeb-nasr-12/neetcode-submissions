class Solution
{
public:
	set<vector<int>> resSet;
	void helper(int index, vector<int> &nums, vector<int> &cur)
	{
		if (index >= nums.size())
		{
			resSet.insert(cur);
			return;
		}
		cur.push_back(nums[index]);
		helper(index + 1, nums, cur);
		cur.pop_back();
		helper(index + 1, nums, cur);
	}

	vector<vector<int>> subsetsWithDup(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		vector<int> cur;
		helper(0, nums, cur);
		vector<vector<int>> res(resSet.begin(), resSet.end());
		return res;
	}
};
