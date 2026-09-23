class Solution
{
public:
	int dr[4] = {-1, 1, 0, 0};
	int dc[4] = {0, 0, -1, 1};

	bool isValid(int r, int c, const vector<vector<int>> &board)
	{
		return r >= 0 && r < board.size() && c >= 0 && c < board[0].size();
	}
	void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int r, int c, int &sum)
	{
		if (!isValid(r, c, grid) || visited[r][c] || grid[r][c] != 1)
			return;
		visited[r][c] = true;
		sum++;

		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			dfs(grid, visited, nr, nc, sum);
		}
	}
	int maxAreaOfIsland(vector<vector<int>> &grid)
	{
		int rows = grid.size();
		int cols = grid[0].size();
		vector<vector<bool>> visited(rows, vector<bool>(cols, false));
		int maxArea = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (!visited[i][j] && grid[i][j] == 1)
				{
					int sum = 0;
					dfs(grid, visited, i, j, sum);
					maxArea = max(maxArea, sum);
				}
			}
		}
		return maxArea;
	}
};
