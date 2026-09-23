
class Solution
{
public:
	set<vector<int>> res;
	void helper(int i, vector<int> &cur, vector<int> &nums)
	{
		if (i >= nums.size())
		{
			res.insert(cur);
			return;
		}
		cur.push_back(nums[i]);
		helper(i + 1, cur, nums);
		cur.pop_back();
		while (i + 1 < nums.size() && nums[i + 1] == nums[i])
		{
			i++;
		}

		helper(i + 1, cur, nums);
	}
	vector<vector<int>> subsetsWithDup(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		vector<int> cur;
		helper(0, cur, nums);
		return vector<vector<int>>(res.begin(), res.end());
	}
};