class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        
        if(grid[0][0]==1 or grid[n-1][n-1]==1)return -1;
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
        pq.push({0,0,0});
        vector<vector<int>>vis(n,vector<int>(n,0));
        int ans=INT_MAX;
        int dir[8][2]={{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            int d=t[0];
            int x=t[1];
            int y=t[2];
            
            if(x==n-1 and y==n-1)ans=min(ans,d);
            
            for(int i=0;i<8;i++){
                int r=x+dir[i][0];
                int c=y+dir[i][1];
                
                if(r>=0 and c>=0 and r<n and c<n and grid[r][c]==0 and vis[r][c]==0){
                    vis[r][c]=1;
                    int dis=d+1;
                    pq.push({dis,r,c});
                }
            }
                
        }
        return ans==INT_MAX?-1:ans+1;
    }
};