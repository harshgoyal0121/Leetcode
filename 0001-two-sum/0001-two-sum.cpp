class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>vec;
        int temp=0;
        unordered_map<int, int>map;
        for(int i=0; i<nums.size(); i++){
            temp=target-nums[i];
            auto it = map.find(temp);
            if(it!=map.end()){
                vec.push_back(i);
                vec.push_back(it->second);
                return vector<int>{it->second, i};
            }
            map[nums[i]]=i;
        }
        return vector<int>{-1};
    }
};