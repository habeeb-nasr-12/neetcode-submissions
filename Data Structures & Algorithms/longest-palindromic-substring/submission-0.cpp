class Solution
{

public:
	int memory[1000][1000];
	string str;
	bool count(int start, int end)
	{
		if (start >= end)
			return 1;
		auto &ret = memory[start][end];
		if (ret != -1)
			return ret;
		bool res;
		if (str[start] == str[end])
			res = count(start + 1, end - 1);
		else
			res = 0;
		ret = res;
		return res;
	}
	string longestPalindrome(string s)
	{
		int n = s.size();
		str = s;
		string res = "";
		int maxPailndrom = 0;
		memset(memory, -1, sizeof(memory));
		for (int i = 0; i < n; i++)
		{

			for (int j = i; j < n; j++)
			{
				int splisedStr = j - i + 1;
				if (count(i, j) && splisedStr > maxPailndrom)
				{
					res = s.substr(i, j - i + 1);
					maxPailndrom = max(maxPailndrom, j - i + 1);
				}
			}
		}
		return res;
	}
};
