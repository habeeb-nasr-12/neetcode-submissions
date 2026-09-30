class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    set<int> container ;
    for(int i =0 ; i<nums.size();i++){
    if(container.count(nums[i])){
     return true; 
     }
     container.insert(nums[i]);
    }
    return false;
    }

};