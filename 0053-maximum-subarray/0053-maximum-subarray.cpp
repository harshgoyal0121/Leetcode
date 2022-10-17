class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // optimal solution
        int sum=0, max_sum=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            sum=sum+nums[i];
            max_sum=max(max_sum, sum);
            if(sum<0)
                sum=0;
        }
        return max_sum;
    
        
        /* brute force
        int sum=0, n=nums.size(), temp=nums[0];
        for(int i=0; i<n; i++){
            sum=0;
            for(int j=i; j<n; j++){
                sum = sum + nums[j];  
                if(sum>temp){
                    temp=sum;
                }
            }
            
        }
        return temp;
        */
    }
};