class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        unordered_set<int> SetNums;
        for (int i = 0; i < nums.size(); i++)
        {
            if (SetNums.count(nums[i]))
                return true;
            SetNums.insert(nums[i]);
        }
        return false;
    }
};