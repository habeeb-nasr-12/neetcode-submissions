class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> numsMap;
        sort(nums.begin(), nums.end());
        for (int num : nums)
        {
            if (!numsMap.count(num) && numsMap.count(num - 1))
                numsMap[num] = ++numsMap[num - 1];
          else if (!numsMap.count(num))
    numsMap[num] = 1;
        }
        int maxTillNow = 0;
        for (auto numPair : numsMap)
        {
            maxTillNow = max(numPair.second, maxTillNow);
        }

        return maxTillNow;
    }
};

