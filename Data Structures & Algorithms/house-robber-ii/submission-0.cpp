
class Solution
{
 
    vector<int> arr;

    int MaxRobbedMoney(int start, int end, int isRobed,  vector<vector<int>>&memory)
    {
        if (start > end)
            return 0;

        auto &ret = memory[start][isRobed];
        if (ret != -1)
            return ret;
        int choice1 = MaxRobbedMoney(start + 1, end, false, memory);
        int choice2 = 0;
        if (!isRobed)
            choice2 = arr[start] + MaxRobbedMoney(start + 1, end, true, memory);

        return ret = max(choice1, choice2);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        vector<vector<int>> memory1(n, vector<int>(2, -1));
        vector<vector<int>> memory2(n, vector<int>(2, -1));
        arr = nums;
        return max(MaxRobbedMoney(1, n - 1, 0, memory1), MaxRobbedMoney(0, n - 2, 0, memory2));
    }
};