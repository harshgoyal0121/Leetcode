//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int start, vector<int>adj[], int vis[]){
        vis[start]=1;
        for(auto it: adj[start]){
            if(!vis[it])  {
                dfs(it, adj, vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> Vadj[V];
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j]==1 && i!=j){
                    Vadj[i].push_back(j);
                    Vadj[j].push_back(i);
                }
            }
        }
        int ans=0;
        int vis[V]={0};
        for(int i=0; i<V; i++){
            if(vis[i]==0){
                ans++;
                dfs(i, Vadj, vis);
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends