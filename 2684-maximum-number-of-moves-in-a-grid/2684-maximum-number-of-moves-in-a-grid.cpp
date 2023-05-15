class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& grid,int prev){
      if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or prev>=grid[i][j])return 0;
     
        int val=grid[i][j];
        
        grid[i][j]=0;
        
        int steps=max({dfs(i-1,j+1,grid,val),dfs(i,j+1,grid,val),dfs(i+1,j+1,grid,val)})+1;
        
        return steps;
            
    }
    int maxMoves(vector<vector<int>>& grid) {
       int  m = grid.size();
       int n = grid[0].size();
        
         int ans=0;
        for(int i=0;i<m;i++){
            ans=max(ans,dfs(i,0,grid,INT_MIN));
            
        }
       return ans-1; 
    }
};