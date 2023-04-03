//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int i, int j, vector<vector<char>>&mat, vector<vector<int>>&vis, int delrow[], int delcol[]){
        vis[i][j]=1;
        int n=mat.size();
        int m=mat[0].size();
        for(int x=0; x<4; x++){
            int r=i+delrow[x];
            int c = j+delcol[x];
            if(r>=0 && c>=0 && r<n && c<m && mat[r][c]=='O' && !vis[r][c]){
                dfs(r, c, mat, vis, delrow, delcol);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n, vector<int>(m,0));
        int delrow[4]={-1, 0, 1, 0};
        int delcol[4]= {0, 1, 0, -1};
        for(int i=0; i<n; i++){
            if(mat[i][0]=='O' && !vis[i][0]){
                dfs(i, 0, mat, vis, delrow, delcol);
            }
            if(mat[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i, m-1, mat, vis, delrow, delcol);
            }
        }
        for(int i=0; i<m; i++){
            if(mat[0][i]=='O' && !vis[0][i]){
                dfs(0, i, mat, vis, delrow, delcol);
            }
            if(mat[n-1][i]=='O' && !vis[n-1][i]){
                dfs(n-1, i, mat, vis, delrow, delcol);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
       
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends