//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int nums[], int n, int k)
    {
        int sum=0, ans=0;
        map<int, int>m;
        m[0]=1;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(m.find(sum-k)!=m.end())  ans+=m[sum-k];
            m[sum]+=1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends