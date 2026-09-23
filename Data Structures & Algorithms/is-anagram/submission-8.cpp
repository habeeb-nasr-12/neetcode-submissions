class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> charScount;
        unordered_map<char, int> charTcount;
        for (char c : s)
            charScount[c]++;
        for (char c : t)
            charTcount[c]++;
        for (char c : s)
        {
            if (!charTcount.count(c) || charTcount[c] == 0)
                return false;
            
            charTcount[c]--;
        }

        for (char c : t)
        {
            if (!charScount.count(c) || charScount[c] == 0)
                return false;
            charScount[c]--;
        }
        return true;
    };
};
