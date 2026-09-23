
class Solution
{

	int helper(int lastRobed, vector<int> &nums, int start, int end, vector<vector<int>> &memory)
	{
		if (start > end)
			return 0;
		auto &ret = memory[start][lastRobed];
		if (ret != -1)
			return ret;
		int rob = 0, doNotRop = 0;
		if (!lastRobed)
			rob = nums[start] + helper(1, nums, start + 1, end, memory);

		doNotRop = helper(0, nums, start + 1, end, memory);
		return ret = max(rob, doNotRop);
	}

public:
	int rob(vector<int> &nums)
	{
		int n = nums.size();
		if (n == 0)
			return 0;
		if (n == 1)
			return nums[0];
		vector<vector<int>> memory1(n, vector<int>(2, -1));
		vector<vector<int>> memory2(n, vector<int>(2, -1));
		return max(helper(1, nums, 0, n - 1, memory1), helper(0, nums, 0, n - 2, memory2));
	}
};
