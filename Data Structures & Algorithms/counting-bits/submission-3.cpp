class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for (int i = 0; i <= n; ++i) {
            bitset <64> bit(i);
            result.push_back(bit.count());
        }
        return result;
    }
};
