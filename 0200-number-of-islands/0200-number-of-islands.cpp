class Solution {
public:
    void bfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>& grid){
        vis[r][c]=1;
        
        int dirc[8][2]={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>>q;
        q.push({r,c});
        
         while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            
            q.pop();
            
            for(auto d:dirc){
                int r=d[0];
                int c=d[1];
                int newr=r+i;
                int newc=c+j;
                if(newr>=0 and newr<grid.size() and newc>=0 and newc<grid[0].size() and vis[newr][newc]==-1 
                and grid[newr][newc]=='1'){
                    vis[newr][newc]=1;
                    q.push({newr,newc});
                }
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,-1));
        
        queue<pair<int,int>>q;
        int ans=0;
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(vis[i][j]==-1 and grid[i][j]=='1'){
                   ans++;
                   bfs(i,j,vis,grid);
               }
           }
        }
        // 0,1  0,2  5,0  5,1  5,3
       
        return ans;
    }
};