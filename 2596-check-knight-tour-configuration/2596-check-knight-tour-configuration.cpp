class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        
        int v=0;
        q.push({0,0});
        
        int n=grid.size();
        while(!q.empty()){
            v++;
            auto f=q.front();
            q.pop();
            
            int i=f.first;
            int j=f.second;
            
            
            if(i-2>=0 and j-1>=0 and grid[i-2][j-1]!=0 and grid[i-2][j-1]==v){
                grid[i-2][j-1]=0;
                q.push({i-2,j-1});
            }
            else if(i-1>=0 and j-2>=0 and grid[i-1][j-2]!=0 and grid[i-1][j-2]==v){
                grid[i-1][j-2]=0;
                q.push({i-1,j-2});
            }
            else if(i+2<n and j-1>=0 and grid[i+2][j-1]!=0 and grid[i+2][j-1]==v){
                grid[i+2][j-1]=0;
                q.push({i+2,j-1});
            }
            else if(i+1<n and j-2>=0 and grid[i+1][j-2]!=0 and grid[i+1][j-2]==v){
                grid[i+1][j-2]=0;
                q.push({i+1,j-2});
            }
            
            else if(i+1<n and j+2<n and grid[i+1][j+2]!=0 and grid[i+1][j+2]==v){
                grid[i+1][j+2]=0;
                q.push({i+1,j+2});
            }
                                             
             else if(i+2<n and j+1<n and grid[i+2][j+1]!=0 and grid[i+2][j+1]==v){
                grid[i+2][j+1]=0;
                q.push({i+2,j+1});
            }
            
            else if(i-1>=0 and j+2<n and grid[i-1][j+2]!=0 and grid[i-1][j+2]==v){
                grid[i-1][j+2]=0;
                q.push({i-1,j+2});
            }                                  
            
            else if(i-2>=0 and j+1<n and grid[i-2][j+1]!=0 and grid[i-2][j+1]==v){
                grid[i-2][j+1]=0;
                q.push({i-2,j+1});
            }                                  
            
        }
        //cout<<v;                                
        if(v==n*n)return true;
                                              
        else
            return false;
                                              
    }
};