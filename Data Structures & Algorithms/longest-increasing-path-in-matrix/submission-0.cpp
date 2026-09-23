class Solution {
public:
    int dp[100][100];
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};

    bool isVaild(int r, int c, vector<vector<int>> &grid) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }

    int helper(int row, int col, vector<vector<int>> &grid) {
        // إذا كان خارج حدود المصفوفة
        if (!isVaild(row, col, grid))
            return 0;
        
        auto &ret = dp[row][col];
        // إذا كان محسوب مسبقاً
        if (ret != -1)
            return ret;
        
        // بما أن المسار يبدأ من الخلية نفسها فيكون على الأقل 1
        int ans = 1;
        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            if (isVaild(newRow, newCol, grid) && grid[newRow][newCol] > grid[row][col])
                ans = max(ans, 1 + helper(newRow, newCol, grid));
        }
        ret = ans;
        return ret;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
            
        memset(dp, -1, sizeof(dp));
        int rows = matrix.size(), cols = matrix[0].size();
        int res = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res = max(res, helper(i, j, matrix));
            }
        }
        return res;
    }
};
