//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMaxAverage(int nums[], int n, int k) {
        // code here
        double sum=0, AvgSum=0, maxSum=0;
        for(int i=0; i<k ; i++) sum+=nums[i];
        AvgSum=sum/k;
        maxSum=AvgSum;
        int ans=0;
        for(int i=1; i<n; i++){
            if(k+i-1 < n){
                sum-=nums[i-1];
                sum+=nums[k+i-1];
                AvgSum = sum/double(k);
            }
            if(maxSum<AvgSum){
                ans = i;
                maxSum=AvgSum;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxAverage(arr, n, k);
        for (int i = ans; i < ans + k; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends