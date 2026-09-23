class Solution
{
public:
	bool isSafe(int r, int c, vector<string> &board)
	{
		int n = board.size();
		// Check column
		for (int i = 0; i < r; i++)
		{
			if (board[i][c] == 'Q')
				return false;
		}

		// Check upper left diagonal
		for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
		{
			if (board[i][j] == 'Q')
				return false;
		}

		// Check upper right diagonal
		for (int i = r, j = c; i >= 0 && j < n; i--, j++)
		{
			if (board[i][j] == 'Q')
				return false;
		}

		return true;
	}

	void backtrack(int r, vector<vector<string>> &res, vector<string> &board)
	{
		if (r == board.size())
		{
			res.push_back(board);
			return;
		}

		for (int col = 0; col < board.size(); col++)
		{
			if (isSafe(r, col, board))
			{
				board[r][col] = 'Q';
				backtrack(r + 1, res, board);
				board[r][col] = '.';
			}
		}
	}

	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>> res;
		vector<string> board(n, string(n, '.'));
		backtrack(0, res, board);
		return res;
	}
};