class Solution
{
public:
    int memory[31];
    int climbStarisNum(int index, int n)
    {
        if(index > n)
        return 0;
        if (index == n)
            return 1;
        auto &ret = memory[index];
        if (ret != -1)
            return ret;
        int climbone = climbStarisNum(index + 1, n);
        int climbTwo = climbStarisNum(index + 2, n);
        return ret = climbone + climbTwo;
    }
    int climbStairs(int n)
    {
        memset(memory, -1, sizeof(memory));
        return climbStarisNum(0, n);
    }
};
