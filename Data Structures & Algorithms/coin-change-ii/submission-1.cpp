class Solution {
public:
    int memory[101][5001];
    vector<int> coinsArr;
    
    int helper(int idx, int amount) {
        if (amount == 0)
            return 1;
        if (idx >= coinsArr.size() || amount < 0)
            return 0;
        
        int &ret = memory[idx][amount];
        if (ret != -1)
            return ret;
        
        int res = 0;
        if (coinsArr[idx] <= amount)
            res = helper(idx, amount - coinsArr[idx]);
        
        res += helper(idx + 1, amount);
        ret = res;
        return res;
    }

    int change(int amount, vector<int> &coins) {
        coinsArr = coins;
        memset(memory, -1, sizeof(memory));
        sort(coinsArr.begin(), coinsArr.end());
        return helper(0, amount);
    }
};
