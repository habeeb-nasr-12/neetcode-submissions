
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            if (target < matrix[i][0] || target > matrix[i][m - 1])
                continue;

            int start = 0, end = m - 1;
            for (int j = 0; j < m; j++)
            {
                int mid = start + (end - start) / 2;
                if (matrix[i][mid] == target)
                    return true;
                else if (matrix[i][mid] > target)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return false;
    }
};
