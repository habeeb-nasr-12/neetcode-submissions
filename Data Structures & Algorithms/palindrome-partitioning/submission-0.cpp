class Solution
{
public:
	vector<vector<string>> res;
	bool isPailndrom(int i, int j, string &s)
	{
		while (i < j)
		{
			if (s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
	void helper(int start, string &s, vector<string> &cur)
	{
		if (start == s.size())
		{
			res.push_back(cur);
			return;
		}

		for (int end = start; end < s.size(); end++)
		{
			if (isPailndrom(start, end, s))
			{
				cur.push_back(s.substr(start, end - start + 1));
				helper(end + 1, s, cur);
				cur.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s)
	{
		vector<string> cur;
		helper(0, s, cur);
		return res;
	}
};
