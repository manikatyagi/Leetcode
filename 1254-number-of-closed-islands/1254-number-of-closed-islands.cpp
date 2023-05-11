class Solution {
public:
    
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>& grid){
        vis[i][j]=1;
         queue<pair<int,int>>q;
        
        int dirc[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        q.push({i,j});
        while(!q.empty()){
            
            int r=q.front().first;
            int c=q.front().second;
            
            q.pop();
            
            for(auto d:dirc){
                int row=r+d[0];
                int col=c+d[1];
                
                if(row>=0 and col>=0 and row<grid.size() and col<grid[0].size() and vis[row][col]==0 and grid[row][col]==0){
                    vis[row][col]=1;
                    q.push({row,col});
                }
            }
            
            
        
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));
       
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 or i==m-1 or j==0 or j==n-1) and grid[i][j]==0 and vis[i][j]==0){
                   bfs(i,j,vis,grid);
                }
            }
        }
        
        int ans=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 and vis[i][j]==0){
                    ans++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        
        
        return ans;
        
    }
};