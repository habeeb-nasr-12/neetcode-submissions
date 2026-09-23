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
		vector<vector<bool>> visitedAtlantic(rows, vector<bool>(cols, false));

		for (int i = 0; i < rows; i++)
		{

			dfs(i, 0, heights, visitedPacific, heights[i][0]);
			dfs(i, cols - 1, heights, visitedAtlantic, heights[i][cols - 1]);
		}
		for (int j = 0; j < cols; j++)
		{
	
				dfs(0, j, heights, visitedPacific, heights[0][j]);
				dfs(rows - 1, j, heights, visitedAtlantic, heights[rows - 1][j]);
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (visitedPacific[i][j] && visitedAtlantic[i][j])
					res.push_back({i, j});
			}
		}

		return res;
	}
};