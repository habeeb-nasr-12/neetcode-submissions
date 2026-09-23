class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        int left = 0, right = heights.size() - 1;
        int res = 0;
        while (left < right)
        {
            int area = min(heights[left], heights[right]) * (right - left);
            res = max(area, res);
            if (heights[right] >= heights[left])
                left++;
            else
                right--;
        }
        return res;
    }
};
