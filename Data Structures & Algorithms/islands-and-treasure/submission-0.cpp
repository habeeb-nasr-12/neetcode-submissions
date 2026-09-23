class Solution
{
public:
	enum
	{
		Water = -1,
		Treasure = 0,
		land = INT_MAX
	};
	int dr[4] = {-1, 1, 0, 0};
	int dc[4] = {0, 0, -1, 1};

	bool isValid(int r, int c, const vector<vector<int>> &board)
	{
		return r >= 0 && r < board.size() && c >= 0 && c < board[0].size();
	}
	void BFS(vector<vector<int>> &grid, int r, int c)
	{
		int rows = grid.size();
		int cols = grid[0].size();
		queue<pair<int, int>> q;
		q.push({r, c});

		while (!q.empty())
		{
			auto [cur_r, cur_c] = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nr = cur_r + dr[i];
				int nc = cur_c + dc[i];
				if (isValid(nr, nc, grid) && grid[nr][nc] != Water && grid[nr][nc] > grid[cur_r][cur_c])
				{
					grid[nr][nc] = grid[cur_r][cur_c] + 1;
					q.push({nr, nc});
				}
			}
		}
	}
	void islandsAndTreasure(vector<vector<int>> &grid)
	{
		int rows = grid.size();
		int cols = grid[0].size();

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (grid[i][j] == Treasure)
				{
					BFS(grid, i, j);
				}
			}
		}
	}
}

;