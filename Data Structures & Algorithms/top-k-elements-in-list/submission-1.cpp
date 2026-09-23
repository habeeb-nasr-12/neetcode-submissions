class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> numsMap;
        for (int num : nums)
        {
            numsMap[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto numsPair : numsMap)
        {
            pq.push({numsPair.second, numsPair.first});
        }
        vector<int> res;

        while (k)
        {
            auto topElment = pq.top();
            pq.pop();
            res.push_back(topElment.second);
            k--;
        }

        return res;
    }
};