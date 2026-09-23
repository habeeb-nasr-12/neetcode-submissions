class Solution
{
public:
	int memory[1000][1000];
	string str;
	int count(int start, int end)
	{
		if (start >= end)
			return 1;
		auto &ret = memory[start][end];
		if (ret != -1)
			return ret;
		int res = 0;
		if (str[start] == str[end])
			res = count(start + 1, end - 1);
		ret = res;
		return res;
	}
	int countSubstrings(string s)
	{
		int n = s.size();
		int res = 0;
		str = s;
		memset(memory, -1, sizeof(memory));
		for (int i = 0; i < n; i++)
		{

			for (int j = i; j < n; j++)
			{
				res += count(i, j);
			}
		}
		return res;
	}
};
