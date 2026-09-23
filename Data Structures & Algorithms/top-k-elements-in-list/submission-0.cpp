class Solution
{
public:
	vector<int> topKFrequent(vector<int> &nums, int k)
	{
		unordered_map<int, int> FrequentArray;
		for (auto num : nums)
			FrequentArray[num]++;
		priority_queue<pair<int, int>> pq;
		vector<int> res;
		for (auto num : FrequentArray)
		{
			pq.push({num.second, num.first});
		}
		while (k != 0)
		{
			res.push_back(pq.top().second);
			pq.pop();
			k--;
		}
		return res;
	}
};