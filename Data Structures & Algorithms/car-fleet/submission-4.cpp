class Solution
{
public:
	int carFleet(int target, vector<int> &position, vector<int> &speed)
	{
		vector<pair<int, int>> pairs;
		for (int i = 0; i < position.size(); i++)
		{
			pairs.push_back({position[i], speed[i]});
		}
		sort(pairs.rbegin(), pairs.rend());
		vector<double> stack;
		for (auto pair : pairs)
		{
			stack.push_back((double)(target - pair.first) / pair.second);
			if (stack.size() >= 2 && stack.back() <= stack[stack.size() - 2])
				stack.pop_back();
		}
		return stack.size();
	}
};
