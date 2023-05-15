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
            
            int d=t[0];
            int i=t[1];
            int j=t[2];
            
            pq.pop();
            
            if(i==n-1 and j==n-1 )ans=min(ans,d);
            for(int k=0;k<8;k++){
                int r=i+dir[k][0];
                int c=j+dir[k][1];
                
                if(r>=0 and r<grid.size() and c>=0 and c<grid.size() and grid[r][c]==0 and vis[r][c]==0){
                    int t=d+1;
                    
                    pq.push({t,r,c});
                    vis[r][c]=1;
                }
                
            }
            
            
        }
        return ans==INT_MAX?-1:ans+1;
    }
};