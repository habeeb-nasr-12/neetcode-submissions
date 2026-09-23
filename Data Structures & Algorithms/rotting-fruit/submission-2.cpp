class Solution
{
	int dr[4] = {0, 0, -1, 1};
	int dc[4] = {1, -1, 0, 0};

public:
	struct cell
	{
		int r, c;
	};

	bool isValid(vector<vector<int>> &matrix, int r, int c)
	{
		return r >= 0 && r < matrix.size() && c >= 0 && c < matrix[0].size();
	}

	int orangesRotting(vector<vector<int>> &grid)
	{
		int rows = grid.size(), cols = grid[0].size();
		vector<vector<bool>> visited(rows, vector<bool>(cols, false));
		queue<cell> q;
		bool fresh = false;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (grid[i][j] == 1)
					fresh = true;
				if (grid[i][j] == 2)
				{
					q.push({i, j});
					visited[i][j] = true;
				}
			}
		}
		if (!fresh)
			return 0;
			
		if (q.empty())
			return -1;

		int level = 0;
		while (!q.empty())
		{
			int sz = q.size();
			while (sz--)
			{
				auto frontCell = q.front();
				q.pop();
				int r = frontCell.r;
				int c = frontCell.c;
				for (int i = 0; i < 4; i++)
				{
					int nr = dr[i] + r;
					int nc = dc[i] + c;
					if (isValid(grid, nr, nc) && grid[nr][nc] == 1 && !visited[nr][nc])
					{
						grid[nr][nc] = 2;
						visited[nr][nc] = true;
						q.push({nr, nc});
					}
				}
			}
			if (!q.empty())
				level++;
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (grid[i][j] == 1)
					return -1;
			}
		}
		return level;
	}
};
