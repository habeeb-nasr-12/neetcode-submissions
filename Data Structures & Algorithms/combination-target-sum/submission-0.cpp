
class Solution
{
public:
	void helper(int i, vector<int> &cur, vector<vector<int>> &res, vector<int> &nums, int target)
	{
		if (target == 0)
		{
			res.push_back(cur);
			return;
		}
		if (i >= nums.size() || target < 0)
			return;

		cur.push_back(nums[i]);
		helper(i, cur, res, nums, target - nums[i]);
		cur.pop_back();
		helper(i + 1, cur, res, nums, target);
	}
	vector<vector<int>> combinationSum(vector<int> &nums, int target)
	{
		vector<int> cur;
		vector<vector<int>> res;
		helper(0, cur, res, nums, target);
		return res;
	}
};