class Solution {
public:
    bool dfs(int x,int y,int t,vector<vector<int>>& grid, vector<vector<int>>&vis,int n){
        
        if(x==n-1 and y==n-1)return true;
        
        vis[x][y]=1;
       
        int dirc[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        
        for(int i=0;i<4;i++){
            int r=x+dirc[i][0];
            int c=y+dirc[i][1];
            
            if(r>=0 and r<grid.size() and c>=0 and c<grid.size() and vis[r][c]==0 and grid[r][c]<=t and grid[x][y]<=t){
                
                if(dfs(r,c,t,grid,vis,n))return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        
        // t will be in between 0 to n*n-1;
        int n=grid.size();
        int low=0;
        int high=(n*n)-1;
         
        while(low<high){
            int mid=(high+low)/2;
            
            vector<vector<int>>vis(n,vector<int>(n,0));
            
            if(dfs(0,0,mid,grid,vis,n)==false){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        
        return low;
    }
};