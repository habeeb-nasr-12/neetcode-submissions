class Solution
{
public:
	int memory[1000][1000];
	int helper(int idx1, int idx2, string &s1, string &s2)
	{
		if (idx1 >= s1.size() || idx2 >= s2.size())
			return 0;
		auto &ret = memory[idx1][idx2];
		if (ret != -1)
			return ret;
		if (idx1 < s1.size() && idx2 < s2.size() && s1[idx1] == s2[idx2])
			return ret = 1 + helper(idx1 + 1, idx2 + 1, s1, s2);

		int skipFirst = helper(idx1 + 1, idx2, s1, s2);
		int skipSecond = helper(idx1, idx2 + 1, s1, s2);
		return ret = max(skipFirst, skipSecond);
	}
	int longestCommonSubsequence(string text1, string text2)
	{
		memset(memory, -1, sizeof(memory));
		return helper(0, 0, text1, text2);
	}
};
