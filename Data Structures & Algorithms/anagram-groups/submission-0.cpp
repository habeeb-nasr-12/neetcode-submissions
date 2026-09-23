class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> stringsMap;
        for (string str : strs)
        {
            string strCopy = str;
            sort(strCopy.begin(), strCopy.end());
            stringsMap[strCopy].push_back(str);
        }
        vector<vector<string>> res;
        for (auto stringItem : stringsMap)
        {
            res.push_back(stringItem.second);
        }
        return res;
    }
};