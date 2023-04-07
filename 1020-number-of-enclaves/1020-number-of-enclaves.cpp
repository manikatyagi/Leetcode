class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                if((i==0 or i==m-1 or j==0 or j==n-1) and grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                   
                }
            }
        }
        vector<int>row={-1,0,+1,0};
        vector<int>col={0,-1,0,+1};
        
        while(!q.empty()){
            auto f=q.front();
            
            int r=f.first;
            int c=f.second;
            q.pop();
            for(int i=0;i<4;i++){
                int x=r+row[i];
                int y=c+col[i];
                
                if(x>=0 and x<m and y>=0 and y<n and vis[x][y]==0 and grid[x][y]==1){
                    vis[x][y]=1;
                    q.push({x,y});
                }
            }
        }
        int ans=0;
         for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 and vis[i][j]==0){
                   ans++;
                }
            }
        }
        
       return ans; 
        
    }
};