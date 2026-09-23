class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> numsMap; // num - freq
        priority_queue<pair<int, int>> pq; // freq - num
        vector<int> res;

        for (int num : nums)
            numsMap[num]++;

        for (auto &entry : numsMap)
            pq.push({entry.second, entry.first});

        while (k > 0 && !pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return res;
    }
};
