class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;
        vector<int> s1W(26, 0), s2W(26, 0);
        for (int i = 0; i < s1.size(); i++)
        {
            s1W[s1[i] - 'a']++;
        }
        // adding the first window
        for (int i = 0; i < s1.size(); i++)
        {
            s2W[s2[i] - 'a']++;
        }
        if (s1W == s2W)
            return true;

        for (int i = s1.size(); i < s2.size(); i++)
        {
            s2W[s2[i] - 'a']++;
            s2W[s2[i - s1.size()] - 'a']--;
            if (s1W == s2W)
                return true;
        }
        return false;
    }
};