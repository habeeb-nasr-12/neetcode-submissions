class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> anagramMap;

        for (string s : strs) {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());
            anagramMap[sortedStr].push_back(s);
        }

        for (pair<const string, vector<string>>& p : anagramMap) {
            res.push_back(p.second);
        }

        return res;
    }
};
