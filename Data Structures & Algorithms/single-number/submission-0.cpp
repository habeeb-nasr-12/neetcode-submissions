class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> numsMap;
        for (int i : nums)
        {
            numsMap[i]++;
        }
        int res;
        for (auto num : numsMap)
        {
            if (num.second == 1)
                res = num.first;
        }
        return res;
    }
};
