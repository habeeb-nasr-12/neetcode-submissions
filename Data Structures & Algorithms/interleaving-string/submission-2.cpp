class Solution
{
	int memory[100 + 1][100 + 1];
	string str1, str2, str3;

	int helper(int idx1, int idx2)
	{
		int k = idx1 + idx2;
		if (idx1 == str1.size() && idx2 == str2.size() && k == str3.size())
			return 1;
		auto &ret = memory[idx1][idx2];
		if (ret != -1)
			return ret;

		int res = 0;
		if (str1[idx1] == str3[k])
			res = helper(idx1 + 1, idx2);
		if (!res && str2[idx2] == str3[k])
			res = helper(idx1, idx2 + 1);
		ret = res;
		return res;
	}

public:
	bool isInterleave(string s1, string s2, string s3)
	{
		str1 = s1, str2 = s2, str3 = s3;
		memset(memory, -1, sizeof(memory));
		return helper(0, 0) == 1;
	}
};
