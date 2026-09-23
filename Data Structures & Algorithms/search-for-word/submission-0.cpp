class Solution
{
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    bool isValid(int r, int c, const vector<vector<char>> &board)
    {
        return r >= 0 && r < board.size() && c >= 0 && c < board[0].size();
    }

    bool backtrack(int index, int row, int col, vector<vector<char>> &board, vector<vector<bool>> &visited, const string &word)
    {
        if (index == word.size()) // إذا وصلنا لنهاية الكلمة، فهذا يعني أننا وجدناها
            return true;

        if (!isValid(row, col, board) || visited[row][col] || board[row][col] != word[index])
            return false;

        // وضع الخلية كمستخدمة
        visited[row][col] = true;

        // تجربة الاتجاهات الأربعة
        for (int i = 0; i < 4; i++)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (backtrack(index + 1, nr, nc, board, visited, word))
                return true; // بمجرد العثور على المسار الصحيح، نوقف البحث
        }

        // إعادة تعيين `visited` عند الرجوع للخلف
        visited[row][col] = false;
        return false;
    }

    bool exist(vector<vector<char>> &board, const string &word)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false)); // مصفوفة زيارة بدلاً من `map`

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++) // `m` بدلاً من `n`
            {
                if (backtrack(0, i, j, board, visited, word))
                    return true;
            }
        }
        return false;
    }
};
