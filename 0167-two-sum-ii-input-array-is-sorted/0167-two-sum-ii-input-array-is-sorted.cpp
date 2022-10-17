class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0, h=n-1;
        int sum=0;
        while(l<h){
            sum=nums[l]+nums[h];
            if(sum<target){
                l++;
            }
            if(sum>target){
                h--;
            }
            if(sum==target){
                return vector<int>{l+1,h+1};
            }   
        }
        return vector<int>{-1};
        /*
        int sum=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            for(int j=n-1; j>=0; j--){
                sum = nums[j] + nums[i];
                if(sum==target){
                    return vector<int>{i+1, j+1};
                }
            }
        }
        return vector<int>{-1,-1};
        */
    }
};