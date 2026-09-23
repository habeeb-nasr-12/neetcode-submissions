
class Solution
{
public:
	set<vector<int>> resSet;
	void helper(int index, vector<int> &nums, vector<int> &cur, int total)
	{
		if (total == 0)
		{
			resSet.insert(cur);
			return;
		}
		if (total < 0 || index == nums.size())
			return;
		cur.push_back(nums[index]);
		helper(index, nums, cur, total - nums[index]);
		cur.pop_back();
		helper(index + 1, nums, cur, total);
	}

	vector<vector<int>> combinationSum(vector<int> &nums, int target)
	{
		vector<int> cur;
		sort(nums.begin(), nums.end());
		helper(0, nums, cur, target);
		vector<vector<int>> res(resSet.begin(), resSet.end());
		return res;
	}
};