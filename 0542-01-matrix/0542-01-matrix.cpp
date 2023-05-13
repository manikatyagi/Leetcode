class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        vector<vector<int>>dist(m,vector<int>(n,0));
        
       
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }
        
        int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int d=q.front().second;
            q.pop();
            dist[i][j]=d;
            vis[i][j]=1;
            for(int k=0;k<4;k++){
                int r=i+dir[k][0];
                int c=j+dir[k][1];
                
                if(r>=0 and r<m and c>=0 and c<n and vis[r][c]==0 and mat[r][c]==1){
                    dist[r][c]=dist[i][j]+1;
                    q.push({{r,c},dist[r][c]});
                    vis[r][c]=1;
                }
            }
            
        }
        return dist;
    }
};