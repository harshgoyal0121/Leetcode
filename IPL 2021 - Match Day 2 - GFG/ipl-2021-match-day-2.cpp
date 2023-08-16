//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> nums, int n, int k) {
        // your code here
        vector<int> ans;

    if (k <= 0 || n == 0) {
        return ans;
    }

    deque<int> dq;  // A double-ended queue to store indices of potential maximum elements

    // Process the first k elements separately to initialize the deque
    for (int i = 0; i < k; i++) {
        // Remove all elements smaller than the current element from the back
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // Process the remaining elements
    for (int i = k; i < n; i++) {
        ans.push_back(nums[dq.front()]);  // The front of the deque holds the maximum element of the current window

        // Remove elements that are out of the current window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove all elements smaller than the current element from the back
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    ans.push_back(nums[dq.front()]);  // Push the maximum element of the last window

    return ans;
}
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends