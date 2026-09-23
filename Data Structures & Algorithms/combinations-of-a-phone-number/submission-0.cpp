class Solution
{
public:
	vector<string> charToDigit{
		"",
		"",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz"};
	vector<string> res;
	void backtrack(int index, string curString, string &digits)
	{
		if (curString.size() == digits.size())
		{
			res.push_back(curString);
			return;
		}
		if (index == digits.size())
			return;
		string chars = charToDigit[digits[index] - '0'];
		for (auto c : chars)
			backtrack(index + 1, curString + c, digits);
	}
	vector<string> letterCombinations(string digits)
	{
		if (digits.empty())
			return res;
		backtrack(0, "", digits);
		return res;
	}
};
