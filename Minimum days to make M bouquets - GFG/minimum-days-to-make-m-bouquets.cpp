//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool func(int x, int m, vector<int>vec, int k){
        int count=0, hand=0;
        for(int i=0; i<vec.size(); i++){
            if(vec[i]<=x)   hand++;
            else hand=0;
            if(hand==k){
                count++;
                hand=0;
            }
        }
        if(count>=m)    return true;
        return false;
    }
    int solve(int m, int k, vector<int> &vec){
      // Code here
      int max=*max_element(vec.begin(), vec.end());
        int min=*min_element(vec.begin(), vec.end());
        int ans=INT_MAX;
        if(m*k>vec.size())  return -1;
        while(min<=max){
            int mid=max-(max-min)/2;
            if(func(mid, m, vec, k)){
                if(ans>mid) ans=mid;
                max=mid-1;
            }
            else{
                min=mid+1;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends