class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // 1 2 6 8 9  1 2 7 9 10
        
          int m=grid.size();
         int n=grid[0].size();
        
        for(int i=1;i<n;i++){               // 1 4 5
            grid[0][i]+=grid[0][i-1];       // 2 7 6
        }                                   // 6 8 7
        
        for(int i=1;i<m;i++){
            grid[i][0]+=grid[i-1][0];
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                grid[i][j]=min(grid[i-1][j]+grid[i][j], grid[i][j-1]+grid[i][j]);
            }
        }
        return grid[m-1][n-1];
    }
};