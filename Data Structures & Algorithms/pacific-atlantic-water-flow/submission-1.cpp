class Solution
{
public:
	int rows, cols;
	int dr[4] = {0, 0, -1, 1};
	int dc[4] = {1, -1, 0, 0};

	bool isValid(vector<vector<int>> &matrix, int r, int c)
	{
		return r >= 0 && r < matrix.size() && c >= 0 && c < matrix[0].size();
	}

	void dfs(int r, int c, vector<vector<int>> &heights, vector<vector<bool>> &visited, int lastVal)
	{
		if (!isValid(heights, r, c) || visited[r][c] || heights[r][c] < lastVal)
			return;
		visited[r][c] = true;

		for (int i = 0; i < 4; i++)
		{
			int nr = dr[i] + r;
			int nc = dc[i] + c;
			if (isValid(heights, nr, nc) && !visited[nr][nc] && heights[nr][nc] >= heights[r][c])
				dfs(nr, nc, heights, visited, heights[r][c]);
		}
	}
	vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
	{
		rows = heights.size(), cols = heights[0].size();
		vector<vector<int>> res;
		vector<vector<bool>> visitedPacific(rows, vector<bool>(cols, false));
		vector<vector<bool>> visitedOceans(rows, vector<bool>(cols, false));
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if ((i == 0 || j == 0) && !visitedPacific[i][j])
					dfs(i, j, heights, visitedPacific, heights[i][j]);

				if ((i == rows - 1 || j == cols - 1) && !visitedOceans[i][j])
					dfs(i, j, heights, visitedOceans, heights[i][j]);
			}
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (visitedPacific[i][j] && visitedOceans[i][j])
					res.push_back({i, j});
			}
		}

		return res;
	}
};