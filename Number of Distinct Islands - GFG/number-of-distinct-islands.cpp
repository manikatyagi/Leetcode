//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   
   
    void dfs(int x,int y,int b1,int b2,vector<vector<int>>&vis,vector<vector<int>>& grid,vector<pair<int,int>>&v){
       vis[x][y]=1;
       int t1=x-b1;
        int t2=y-b2;
            
        v.push_back({t1,t2});
        
        int dirc[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
        
        for(int i=0;i<4;i++){
            int r=x+dirc[i][0];
            int c=y+dirc[i][1];
            
            if(r>=0 and r<grid.size() and c>=0 and c<grid[0].size() and vis[r][c]==0 and grid[r][c]==1)
                dfs(r,c,b1,b2,vis,grid,v);
        }
       
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>se;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(vis[i][j]==0 and grid[i][j]==1){
                    vector<pair<int,int>>v;
                    dfs(i,j,i,j,vis,grid,v);
                    se.insert(v);
                    
                }
            }
        }
        
        return se.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends