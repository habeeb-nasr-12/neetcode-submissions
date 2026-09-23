class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (nums.empty() || k <= 0)
            return {};
        vector<int> res;
        int l = 0;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k && i < nums.size(); i++)
        {
            pq.push({nums[i], i});
        }
        if (!pq.empty())
            res.push_back(pq.top().first);
        for (int r = k; r < nums.size(); r++)
        {
            pq.push({nums[r], r});
            l++;
            while (!pq.empty() && pq.top().second < l)
            {
                pq.pop();
            }
            if (!pq.empty())
                res.push_back(pq.top().first);
        }
        return res;
    }
};