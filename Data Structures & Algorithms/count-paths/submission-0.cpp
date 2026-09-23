class Solution
{
	int memory[100 + 1][100 + 1];
	int rows, cols;
	bool isVaild(int r, int c)
	{
		return r >= 0 && r < rows && c >= 0 && c < cols;
	}
	int helper(int r, int c)
	{
		if (!isVaild(r, c))
			return 0;
		if (r == rows - 1 && c == cols - 1)
			return 1;
		auto &ret = memory[r][c];
		if (ret != -1)
			return ret;
		int moveRight = helper(r, c + 1);
		int moveBottom = helper(r + 1, c);
		return ret = moveRight + moveBottom;
	}

public:
	int uniquePaths(int m, int n)
	{
		rows = m, cols = n;
		memset(memory, -1, sizeof(memory));
		return helper(0, 0);
	}
};
