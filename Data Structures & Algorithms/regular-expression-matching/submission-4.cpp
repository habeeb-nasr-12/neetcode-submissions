class Solution
{
	int dp[20][20];

public:
	bool helper(int i, int j, string &s, string &p)
	{
		if (j == p.size())
			return i == s.size();

		auto &ret = dp[i][j];
		if (ret != -1)
			return ret;
		bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');
		if (j + 1 < p.size() && p[j + 1] == '*')
			ret =   helper(i , j + 2, s, p) || match && helper(i + 1, j, s, p);
		else
			ret = match && helper(i + 1, j + 1, s, p);

		return ret;
	}

	bool isMatch(string s, string p)
	{
		memset(dp, -1, sizeof(dp));
		return helper(0, 0, s, p);
	}
};