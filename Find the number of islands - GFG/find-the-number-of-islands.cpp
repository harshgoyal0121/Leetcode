//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
        // i is row && j is column
        vis[i][j]=1;
        queue<pair<int, int>>q;
        q.push({i, j});
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            //accessing in all eight direction
            for(int deltrow=-1; deltrow<=1; deltrow++){
                for(int deltcol=-1; deltcol<=1; deltcol++){
                    int nrow = deltrow+r;
                    int ncol = deltcol+c;
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i, j, grid, vis);
                }
            }
            
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends