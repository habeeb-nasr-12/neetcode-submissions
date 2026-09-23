class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;
        int l = 0;
        int res = 0;
        unordered_set<char> setDb;
        for (int r = 0; r < s.size(); r++)
        {
            while (setDb.count(s[r]))
            {
                setDb.erase(s[l]);
                l++;
            }

            setDb.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};

