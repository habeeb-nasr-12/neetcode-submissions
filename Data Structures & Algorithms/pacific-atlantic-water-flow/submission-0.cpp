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

	void dfs(int r, int c, vector<vector<int>> &heights, vector<vector<bool>> &visited, int lastVal, bool &touchPacific, bool &touchAtlantic)
	{
		if (!isValid(heights, r, c) || visited[r][c] || heights[r][c] > lastVal)
			return;
		visited[r][c] = true;
		if (r == 0 || c == 0)
			touchPacific = true;
		if (r == rows - 1 || c == cols - 1)
			touchAtlantic = true;
		if (touchAtlantic && touchPacific)
			return;

		for (int i = 0; i < 4; i++)
		{
			int nr = dr[i] + r;
			int nc = dc[i] + c;
			if (isValid(heights, nr, nc) && !visited[nr][nc] && heights[nr][nc] <= heights[r][c])
				dfs(nr, nc, heights, visited, heights[r][c], touchPacific, touchAtlantic);
		}
	}
	vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
	{
		rows = heights.size(), cols = heights[0].size();
		vector<vector<int>> res;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				vector<vector<bool>> visited(rows, vector<bool>(cols, false));
				bool touchPacific = false;
				bool touchAtlantic = false;
				dfs(i, j, heights, visited, INT_MAX, touchPacific, touchAtlantic);
				if (touchPacific && touchAtlantic)
					res.push_back({i, j});
			}
		}
		return res;
	}
};