//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int pairs(vector<int>&nums, int low, int mid, int high){
        int cnt=0;
        int x=mid+1;
        for(int i=low; i<=mid; i++){
            int count=0;
            while(x<=high && nums[i]>(long long)2*nums[x])  x++;
            cnt+=x-(mid+1);
        }
        return cnt;
    }
    void merge(vector<int>&nums, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        vector<int>temp;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low; i<=high; i++){
            nums[i]=temp[i-low];
        }
    }
    int mergeSort(vector<int>&nums, int low, int high){
        int cnt=0;
        if(low>=high)   return cnt;
        int mid = low+(high-low)/2;
        cnt+=mergeSort(nums, low, mid);
        cnt+=mergeSort(nums, mid+1, high);
        cnt+=pairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return cnt;
    }
    int countRevPairs(int n, vector<int> arr) {
        // Code here
        return mergeSort(arr, 0, n-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends