
class Solution
{
public:
	int dp[1000][1000];
	int helper(int i, int j, string &s, string &t)
	{
		if (j == t.size())
			return 1;
		if (i == s.size())
			return 0;
		auto &ret = dp[i][j];
		if (ret != -1)
			return ret;
		ret = helper(i + 1, j, s, t);
		if (s[i] == t[j])
			ret += helper(i + 1, j + 1, s, t);
		return ret;
	}

	int numDistinct(string s, string t)
	{
		memset(dp, -1, sizeof(dp));
		return helper(0, 0, s, t);
	}
};
