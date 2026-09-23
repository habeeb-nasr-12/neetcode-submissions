class Solution
{
	int memory[20 + 1][20000];
	int total;
	int findTargetSum(int idx, int cur, vector<int> &nums)
	{

		if (idx == nums.size())
			return cur == total ? 1 : 0;
		auto &ret = memory[idx][cur];
		if (ret != -1)
			return ret;
		int plus = findTargetSum(idx + 1, cur + nums[idx], nums);
		int minus = findTargetSum(idx + 1, cur - nums[idx], nums);
		return ret = plus + minus;
	}

public:
	int findTargetSumWays(vector<int> &nums, int target)
	{
		total = target;
		int n = nums.size();
		memset(memory, -1, sizeof(memory));
		return findTargetSum(0, 0, nums);
	}
};

