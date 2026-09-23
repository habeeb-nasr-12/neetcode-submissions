class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> numsMap;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (numsMap.count(target - nums[i]))
            {
                res.push_back(numsMap[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            numsMap[nums[i]] = i;
        }
        return res;
    }
};
