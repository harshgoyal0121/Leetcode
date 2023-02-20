//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  public:
  bool func(int x, vector<int>piles, int h){
        int count=0;
        for(int i=0; i<piles.size(); i++){
            count+=piles[i]/x;
            if(piles[i]%x>0)    count++;
        }
        if(count<=h)    return true;
        return false;
    }
    int Solve(int N, vector<int>& piles, int h) {
        // Code here
        int max=1e9, min=1;
        int ans=INT_MAX;
        while(min<=max){
            int mid=max-(max-min)/2;
            if(func(mid, piles, h)){
                if(ans>mid) ans=mid;
                max=mid-1;
            }
            else{
                min=mid+1;
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
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends