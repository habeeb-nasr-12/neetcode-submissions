class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> group;
        for(int i=0 ; i < nums.size();i++){
            int firstNumber=target-nums[i];
            if(group.count(firstNumber)){
                return {group[firstNumber], i};
            }
           
           group.insert({nums[i], i});
        }
        return {};
    }
};
