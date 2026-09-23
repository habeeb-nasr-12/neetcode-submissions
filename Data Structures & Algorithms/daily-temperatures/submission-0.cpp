class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stk; // index,value
        for (int i = 0; i < temperatures.size(); i++)
        {
            int t = temperatures[i];
            while (!stk.empty() && t > stk.top().second)
            {
                auto pair = stk.top();
                stk.pop();
                res[pair.first] = i - pair.first;
            }

            stk.push({i, temperatures[i]});
        }
        return res;
    }
};
