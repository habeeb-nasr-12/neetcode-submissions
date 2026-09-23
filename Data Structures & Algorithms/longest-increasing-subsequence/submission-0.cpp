class Solution
{
public:
	int dp[1001][1001];
	int LIS(int index, int prv, vector<int> &nums)
	{
		if (index == nums.size())
			return 0;

		auto &ret = dp[index][prv+1];
		if (ret != -1)
			return ret;
	
		ret = LIS(index + 1, prv, nums);

		if (nums[prv] < nums[index] || prv == -1)
			return ret = max(ret, 1 + LIS(index + 1, index, nums));
		return ret;
	}
	int lengthOfLIS(vector<int> &nums)
	{
        if (nums.empty())
            return 0;
		int sz = nums.size();
		memset(dp, -1, sizeof(dp));
		return LIS(0, -1, nums);
	}
};

