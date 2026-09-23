
class Solution
{
public:
	int memory[300][300];
	int helper(int start, int end, vector<int> &nums)
	{
		if (start + 1 == end)
			return 0;

		auto &ret = memory[start][end];
		if (ret != -1)
			return ret;

		int maxCoins = 0;
		for (int i = start + 1; i < end; i++)
		{
			int cur = nums[start] * nums[i] * nums[end] + helper(start, i, nums) + helper(i, end, nums);
			maxCoins = max(maxCoins, cur);
		}
        ret= maxCoins;
		return ret;
	}

	int maxCoins(vector<int> &nums)
	{
		if (nums.empty())
			return 0;
		vector<int> arr;
		arr.push_back(1);
		for (int num : nums)
			arr.push_back(num);
		arr.push_back(1);
		int n = arr.size();
		memset(memory, -1, sizeof(memory));
		return helper(0, n - 1, arr);
	}
};