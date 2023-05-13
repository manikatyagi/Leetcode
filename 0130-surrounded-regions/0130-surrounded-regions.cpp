class Solution {
public:
    void bfs(int x,int y,vector<vector<int>>&vis,vector<vector<char>>&board){
        vis[x][y]=1;
         int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
        queue<pair<int,int>>q;
        
        q.push({x,y});
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            
            q.pop();
            
            for(int k=0;k<4;k++){
                int r=i+dir[k][0];
                int c=j+dir[k][1];
                
                if(r>=0 and r<board.size() and c>=0 and c<board[0].size() and vis[r][c]!=1 and board[r][c]=='O'){
                    q.push({r,c});
                    vis[r][c]=1;
                }
            }
            
        }
    }
    void solve(vector<vector<char>>& board) {
        
        int m=board.size();
        int n=board[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 or j==0 or i==m-1 or j==n-1) and vis[i][j]==0 and board[i][j]=='O'){
                   bfs(i,j,vis,board);
                }
                    
            }
        }
        
        
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 and board[i][j]=='O'){
                   board[i][j]='X';
                }
                    
            }
        }
     
    }
};