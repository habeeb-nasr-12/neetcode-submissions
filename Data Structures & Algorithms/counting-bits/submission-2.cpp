class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res;
        for (int i = 0; i <= n; i++)
        {
            bitset<64> bunm(i);
            int countBnum = bunm.count();
            res.push_back(countBnum);
        }
        return res;
    }
};
