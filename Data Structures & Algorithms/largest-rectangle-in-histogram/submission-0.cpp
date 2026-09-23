class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<pair<int, int>> stk; // index ,value
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            int start = i;
            while (!stk.empty() && stk.top().second >= heights[i])
            {
                auto pair = stk.top();
                int index = stk.top().first;
                int height = stk.top().second;
                maxArea = max(maxArea, height * (i - index));
                stk.pop();
                start = index;
            }
            stk.push({start, heights[i]});
        }
        while (!stk.empty())
        {
            auto pair = stk.top();
            int index = stk.top().first;
            int height = stk.top().second;
            maxArea = max(maxArea, height * int(heights.size() - index));
            stk.pop();
        }
        return maxArea;
    }
};
