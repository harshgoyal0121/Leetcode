//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid, int delrow[], int delcol[]){
        vis[i][j]=1;
        int n=grid.size();
        int m= grid[0].size();
        for(int x=0; x<4; x++){
            int r=i+delrow[x];
            int c= j+delcol[x];
            if(r>=0 && c>=0 && r<n && c<m && !vis[r][c] && grid[r][c]==1){
                dfs(r, c, vis, grid, delrow, delcol);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m =grid[0].size();
        int delrow[4]={-1, 0, 1, 0};
        int delcol[4]={0, 1, 0, -1};
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0; i<m; i++){
            if(!vis[0][i] && grid[0][i]==1)
                dfs(0, i, vis, grid, delrow, delcol);
            if(!vis[n-1][i] && grid[n-1][i]==1)
                dfs(n-1, i, vis, grid, delrow, delcol);
        }
        for(int i=0; i<n; i++){
            if(!vis[i][0] && grid[i][0]==1)
                dfs(i, 0, vis, grid, delrow, delcol);
            if(!vis[i][m-1] && grid[i][m-1]==1)
                dfs(i, m-1, vis, grid, delrow, delcol);
        }
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends