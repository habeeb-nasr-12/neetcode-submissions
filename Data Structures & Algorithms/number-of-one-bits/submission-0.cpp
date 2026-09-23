class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        bitset<64> bit(n);
        return bit.count();
    }
};
