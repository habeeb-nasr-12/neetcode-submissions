class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;
        for (char c : s)
        {
            sMap[c]++;
        }
        for (char c : t)
        {
            tMap[c]++;
        }
        for (char c : s)
        {
            if (!tMap.count(c) || tMap[c] == 0)
                return false;
            tMap[c]--;
        }

        for (char c : t)
        {
            if (!sMap.count(c) || sMap[c] == 0)
                return false;
            sMap[c]--;
        }

        return true;
    }
};
