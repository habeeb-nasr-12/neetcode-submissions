class Solution
{
public:
	int memory[5000][3][2];
	vector<int> pricesArr;
	enum
	{
		BUY = 1,
		SELL = 2,
		doNothing = 0

	};

	int helper(int idx, int LastTransiction, bool haveAstock)
	{
		if (idx == pricesArr.size())
			return 0;
		auto &ret = memory[idx][LastTransiction][haveAstock];
		if (ret != -1)
			return ret;
		int buy = 0, sell = 0, noThing = 0;
		if (haveAstock)
			sell = pricesArr[idx] + helper(idx + 1, SELL, 0);
		else if (LastTransiction != SELL)
			buy = -pricesArr[idx] + helper(idx + 1, BUY, 1);
		noThing = helper(idx + 1, doNothing, haveAstock);
		return ret = max(buy, max(sell, noThing));
	}

	int maxProfit(vector<int> &prices)
	{
		pricesArr = prices;
		memset(memory, -1, sizeof(memory));
		return helper(0, 0, 0);
	}
};
