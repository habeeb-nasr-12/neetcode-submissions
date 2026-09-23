class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int l = 0;
        int res = 0;
        for (int r = 0; r < prices.size(); r++)
        {
            while (prices[r] < prices[l])
            {
                l++;
            }
            res = max(res, prices[r] - prices[l]);
        }
        return res;
    }
};
