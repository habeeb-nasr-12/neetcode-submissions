class Solution
{
public:
	int memory[100 + 1];
	bool canTwoStep(int idx, string &s)
	{
		string splisedStr = s.substr(idx, 2);
		int splisedNumber = stoi(splisedStr);
		return idx + 2 <= s.size() && splisedNumber >= 10 && splisedNumber <= 26;
	}
	int helper(int idx, string &s)
	{
		if (idx == s.size())
			return 1;
		auto &ret = memory[idx];
		if (ret != -1)
			return ret;
		int oneStep = 0, twoStep = 0;
		if (s[idx] == '0')
			return 0;

		oneStep = helper(idx + 1, s);

		if (canTwoStep(idx, s))
			twoStep = helper(idx + 2, s);
		return ret = oneStep + twoStep;
	}

	int numDecodings(string s)
	{
		if (s.empty())
			return 0;

		memset(memory, -1, sizeof(memory));
		return helper(0, s);
	}
};
