//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int nums[], int n)
    {
      //Your code here
      int cnt=0;
        map<int, int>m;
        for(int i =0; i<n; i++){
            m[nums[i]]=i;
        }
        vector<vector<int>>vec;
        for(int i=0; i<n; i++){
            cnt=0;
            int x=nums[i];
            vector<int>v;
            v.push_back(x);
            for(int j=0; j<n; j++){
                if(i==j)    continue;
                x++;
                if(m.find(x)!=m.end())  v.push_back(x);
                else break;
            }
            vec.push_back(v);
        }
        int maxi=0;
        for(int i=0; i<vec.size(); i++){
            int x = vec[i].size();
            maxi = max(maxi, x);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends