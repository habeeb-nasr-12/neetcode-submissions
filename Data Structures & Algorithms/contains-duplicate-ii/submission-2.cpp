
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        if(k==0)
        return false;
        int l = 0;
        for (int r = 1; r < nums.size(); r++)
        {
            while (abs(r - l) > k)
            {
                l++;
            }

            if (nums[l] == nums[r] && abs(r - l) <= k)
                return true;
        }
        return false;
    }
};