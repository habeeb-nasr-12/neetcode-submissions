class Solution
{
public:
    // int binary_search(vector<int> &nums, int l, int r)
    // {

    // }
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        int pivot = 0;
        int res = INT_MAX;
        while (l < r)
        {
            int mid = (r + l) / 2;
            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        pivot = l;
        res = min(res, nums[pivot]);
        // res = min(res, binary_search(nums, 0, pivot - 1));
        return res;
    }
};
