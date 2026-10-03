 class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& word : strs) {
            int count[26] = {0};          // reset to zero for each word
            for (char c : word) {
                count[c - 'a']++;
            }

            string key;
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + "a";
            }

            groups[key].push_back(word);
        }

        vector<vector<string>> res;
        for (auto& group : groups) {
            res.push_back(group.second);
        }
        return res;
    }
};