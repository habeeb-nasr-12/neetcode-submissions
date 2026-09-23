class Solution
{
public:
	bool isValidSudoku(vector<vector<char>> &board)
	{
		int rows = board.size();
		int cols = board[0].size();
		unordered_map<int, unordered_set<char>> rowsSeen;
		unordered_map<int, unordered_set<char>> colSeen;
		map<pair<int, int>, unordered_set<char>> square;
		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < cols;c++)
			{
				if (board[r][c] == '.')
					continue;
				pair<int, int> squareKey = {r / 3, c / 3};
				if (rowsSeen[r].count(board[r][c]) || colSeen[c].count(board[r][c]) || square[squareKey].count(board[r][c]))
					return false;
				rowsSeen[r].insert(board[r][c]);
				colSeen[c].insert(board[r][c]);
				square[squareKey].insert(board[r][c]);
			}
		}
		return true;
	}
};