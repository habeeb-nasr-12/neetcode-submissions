class Solution
{
public:
    int binary_search(vector<int> &nums, int target, int l, int r)
    {
        while (l <= r)
        {
            int mid = (r + l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        int pivot = 0;
        while (l < r)
        {
            int mid = (r + l) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        pivot = l;
        int res = binary_search(nums, target, pivot, nums.size() - 1);
        
        if (res != -1)
            return res;

        return binary_search(nums, target, 0, pivot-1);
    }
};