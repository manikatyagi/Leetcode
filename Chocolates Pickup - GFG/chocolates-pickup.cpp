//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int func(int n, int m,vector<vector<int>>& grid,int j1,int j2,int i,vector<vector<vector<int>>>&dp){
        
        if(j1<0 or j1>=m or j2<0 or j2>=m)return -1e9;
        
        if(i==n-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else
             return grid[i][j2]+grid[i][j1];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        
        int maxi=-1e9;
        
        for(int ij1=-1;ij1<=1;ij1++){
            
            for(int ij2=-1;ij2<=1;ij2++){
                
                int val=0;
                
                if(j1==j2)val=grid[i][j1];
                
                else 
                  val=grid[i][j1]+grid[i][j2];
                
                
                val+=func(n,m,grid,ij1+j1,ij2+j2,i+1,dp);
                
                maxi=max(maxi,val);
            }
        }
        
        return dp[i][j1][j2]=maxi;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        
        return func(n,m,grid,0,m-1,0,dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends