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
        return charScount == charTcount;
    };
};
