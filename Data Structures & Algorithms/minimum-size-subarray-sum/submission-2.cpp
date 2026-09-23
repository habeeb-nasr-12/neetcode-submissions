class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int l = 0, res = INT_MAX, sum = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            sum += nums[r];
            while (l <= r && sum >= target)
            {
                res = min(res, (r - l + 1));
                sum-=nums[l];
                l++;
            }
        }
        if (res == INT_MAX)
            return 0;

        return res;
    }
};