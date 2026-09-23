class Solution
		{
		public:
			int memory[100][5000];

			int helper(int idx, int cur, vector<int> &nums)
			{
				if (cur == 0)
					return 1;
				if (cur < 0 || idx == nums.size())
					return 0;

				auto &ret = memory[idx][cur];
				if (ret != -1)
					return ret;

				int take = helper(idx + 1, cur - nums[idx], nums);
				int leave = helper(idx + 1, cur, nums);

				ret = take || leave;
				return ret;
			}

			bool canPartition(vector<int> &nums)
			{
				int sum = accumulate(nums.begin(), nums.end(), 0);
				memset(memory, -1, sizeof(memory));
				int target = sum / 2;
				if (sum % 2 != 0)
					return false;
				return helper(0, sum / 2, nums);
			}
		};