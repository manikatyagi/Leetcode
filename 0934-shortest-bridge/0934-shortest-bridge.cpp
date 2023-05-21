class Solution {
public:
    void dfs(int x,int y,queue<pair<int,int>>&q,vector<vector<int>>& grid,int n, vector<vector<int>>&vis){
        
        if(x<0 or y<0 or x>=n or y>=n or vis[x][y]==1 or grid[x][y]==0)return ;
        
        vis[x][y]=1;
        q.push({x,y});
        
        dfs(x,y+1,q,grid,n,vis);
        dfs(x+1,y,q,grid,n,vis);
        dfs(x-1,y,q,grid,n,vis);
        dfs(x,y-1,q,grid,n,vis);
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n=grid.size();
        
        queue<pair<int,int>>q;

        bool found=false;
        vector<vector<int>>vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            
            if(found)break;
            
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                   
                    dfs(i,j,q,grid,n,vis);
                    found=true;
                    break;
                    
                }
            }
        }
        int dirc[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            
            while(s-->0){
                int x=q.front().first;
                int y=q.front().second;
                
                q.pop();
                
                for(int i=0;i<4;i++){
                    int r=x+dirc[i][0];
                    int c=y+dirc[i][1];
                    if(r>=0 and r<n and c>=0 and c<n and vis[r][c]==0){
                        if(grid[r][c]==1)return ans;
                        
                        vis[r][c]=1;
                        q.push({r,c});
                        
                    } 
                    
                }
            }
            ans++;
        }
        return ans;
    }
};