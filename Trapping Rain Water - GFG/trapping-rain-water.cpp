//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int nums[], int n){
        // code here
        int l=0, r=n-1;
        long long left=0, right=0;
        long long ans = 0;
        while(l<=r){
            if(nums[l]<=nums[r]){
                if(nums[l]>=left)   left = nums[l];
                else    ans+=(left-nums[l]);
                l++;
            }
            else{
                if(nums[r]>=right)   right = nums[r];
                else    ans+=(right-nums[r]);
                r--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends