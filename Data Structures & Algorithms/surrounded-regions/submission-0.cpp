class Solution
{
public:
	int dr[4] = {0, 0, -1, 1};
	int dc[4] = {1, -1, 0, 0};

	bool isValid(vector<vector<char>> &matrix, int r, int c)
	{
		return r >= 0 && r < matrix.size() && c >= 0 && c < matrix[0].size();
	}
	struct Cell
	{
		int r, c;
	};

	void dfs(int r, int c, vector<vector<bool>> &visited, vector<vector<char>> &board, bool &isSrounded, vector<Cell> &SroundedCells)
	{
		if (!isValid(board, r, c))
		{
			isSrounded = false;
			return;
		}
		if (visited[r][c] || board[r][c] == 'X')
			return;
		visited[r][c] = true;
		SroundedCells.push_back({r, c});
		for (int i = 0; i < 4; i++)
		{
			int nr = dr[i] + r;
			int nc = dc[i] + c;

				dfs(nr, nc, visited, board, isSrounded, SroundedCells);
		}
	}

	void solve(vector<vector<char>> &board)
	{
		int rows = board.size(), cols = board[0].size();
		vector<vector<bool>> visited(rows, vector<bool>(cols, false));

		for (int i = 0; i < rows; i++)
		{

			for (int j = 0; j < cols; j++)
			{
				if (!visited[i][j] && board[i][j] == 'O')
				{
					bool isSrounded = true;
					vector<Cell> SroundedCells;
					dfs(i, j, visited, board, isSrounded, SroundedCells);
					if (isSrounded)
					{
						for (int i = 0; i < SroundedCells.size(); i++)
						{
							Cell cell = SroundedCells[i];
							board[cell.r][cell.c] = 'X';
						}
					}
				}
			}
		}
	}
};
