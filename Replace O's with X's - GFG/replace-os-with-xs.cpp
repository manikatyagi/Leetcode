//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int x,int y,vector<vector<int>>&vis,vector<vector<char>>&mat){
        
        if(mat[x][y]=='O' and !vis[x][y]) vis[x][y]=1;
        
         int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
         
          int n=mat.size();
          int m=mat[0].size();
          
          for(int i=0;i<4;i++){
              int r=x+dir[i][0];
              int c=y+dir[i][1];
              
              if(r>=0 and r<n and c>=0 and c<m and vis[r][c]!=1 and mat[r][c]=='O'){
                    dfs(r,c,vis,mat);
                }
          }
        
    
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        
        vector<vector<int>>vis(n,vector<int>(m,0));
         //vector<vector<int>>dis(m,vector<int>(n,0));

         // first row and last row
        for(int j=0;j<m;j++){
            
            if(!vis[0][j] and mat[0][j]=='O'){
                dfs(0,j,vis,mat);
            }
            
            if(!vis[n-1][j] and mat[n-1][j]=='O'){
                dfs(n-1,j,vis,mat);
            }
            
        }
        
        // first col and last col
        for(int j=0;j<n;j++){
            
            if(!vis[j][0] and mat[j][0]=='O'){
                dfs(j,0,vis,mat);
            }
            
            if(!vis[j][m-1] and mat[j][m-1]=='O'){
                dfs(j,m-1,vis,mat);
            }
            
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 and mat[i][j]=='O'){
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