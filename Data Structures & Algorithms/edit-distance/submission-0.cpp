class Solution
{
public:
	int dp[100][100];
	int helper(int idx1, int idx2, string &word1, string &word2)
	{
		if (idx1 == word1.size() && idx2 < word2.size())
			return word2.size() - idx2;
		if (idx2 == word2.size() && idx1 < word1.size())
			return word1.size() - idx1;
		if (idx1 == word1.size() && idx2 == word2.size())
			return 0;
		auto &ret = dp[idx1][idx2];
		if (ret != -1)
			return ret;
		if (word1[idx1] == word2[idx2])
			return helper(idx1 + 1, idx2 + 1, word1, word2);
		int insert = 1 + helper(idx1 + 1, idx2, word1, word2);
		int Delete = 1 + helper(idx1, idx2 + 1, word1, word2);
		int change = 1 + helper(idx1 + 1, idx2 + 1, word1, word2);
		return ret = min(insert, min(change, Delete));
	}
	int minDistance(string word1, string word2)
	{
		memset(dp, -1, sizeof(dp));
		return helper(0, 0, word1, word2);
	}
};
