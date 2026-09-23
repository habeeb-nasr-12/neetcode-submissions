class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int l = 0;
        deque<int> closestDeque;
        for (int r = 0; r < arr.size(); r++)
        {
            if ((r - l + 1) > k &&
                (abs(arr[r] - x) < abs(closestDeque.front() - x) ||
                 (abs(arr[r] - x) == abs(closestDeque.front() - x) &&
                  arr[r] < closestDeque.front())))
            {
                l++;
                closestDeque.pop_front();
                closestDeque.push_back(arr[r]);
            }
            else if ((r - l + 1) <= k)
            {
                closestDeque.push_back(arr[r]);
            }
        }
        vector<int> res;
        for (int i = 0; i < closestDeque.size(); i++)
        {
            res.push_back(closestDeque[i]);
        }

        return res;
    }
};