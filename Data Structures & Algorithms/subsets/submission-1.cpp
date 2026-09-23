class Solution
{
public:
	vector<vector<int>> res;
	void helper(int index, vector<int> &nums, vector<int> &cur)
	{
		if (index >= nums.size())
		{
			res.push_back(cur);
			return;
		}
		cur.push_back(nums[index]);
		helper(index + 1, nums, cur);
		cur.pop_back();
		helper(index + 1, nums, cur);
	}

	vector<vector<int>> subsets(vector<int> &nums)
	{
		vector<int> cur;
		helper(0, nums, cur);
		return res;
	}
};
