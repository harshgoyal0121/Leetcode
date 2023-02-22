//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int nums[], int n){
	    //code
        if(n==1 || nums[0]!=nums[1])    return nums[0];
        int l=1, r=n-1, mid=0;
        while(l<=r){
            mid = r-(r-l)/2;
            if(mid%2==0 ){
                if(nums[mid]==nums[mid+1])  l=mid+1;
                else if(nums[mid]==nums[mid-1]) r=mid-1;
                else return nums[mid];
            }
            else{
                if(nums[mid]==nums[mid-1])  l=mid+1;
                else r=mid-1;
            }
        }
        return nums[mid];	    
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends