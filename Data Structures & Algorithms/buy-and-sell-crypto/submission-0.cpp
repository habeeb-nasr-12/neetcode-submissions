class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		int maxValue = INT_MIN;
		int maxProfit = 0;
		for (int i = prices.size() - 1; i >= 0; i--)
		{
			maxValue = max(maxValue, prices[i]);
			maxProfit = max(maxProfit, maxValue - prices[i]);
		}
		return maxProfit;
	}
};
