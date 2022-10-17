class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //brute force solution
        /*
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]==nums[j])
                    return true;
            }
        }
        return false;
        */
        
        unordered_map<int, int>map;
       
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }
        for(auto it: map){
            if(it.second>1)
                return true;
        }
        return false;
    }
};