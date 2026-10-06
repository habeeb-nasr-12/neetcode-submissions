class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> group ; // num ,freq 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
     
     for (int i = 0; i < nums.size(); i++) 
        group[nums[i]]++;  
    
    for (auto& elem : group) {
    heap.push({elem.second , elem.first});
    if(heap.size() > k)
    heap.pop();
    }
   vector<int> res;
    while(k>0 && !heap.empty()){
        int top = heap.top().second;
        heap.pop();
        res.push_back(top);
        k--;
    }
    return res;
    }
};
