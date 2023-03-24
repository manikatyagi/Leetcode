class Solution {
public:
    void dfs( vector<vector<pair<int,int>>>&adj,vector<vector<int>>& conn,int node,int &c,vector<bool>&vis){
        vis[node]=1;
        
        for(auto x:adj[node]){
            
            if(!vis[x.first]){
                
                if(x.second==1){
                    c++;
                }
                dfs(adj,conn,x.first,c,vis);
            }
        }
     
        
    }
    int minReorder(int n, vector<vector<int>>& conn) {
        //       0            1                2      3          4             5
        // [ [[1 1] [4 -1]] [[0 -1][3 1]]  [[3 1]]  [[2,-1]] [[0,1] [5,1]]  [[4,-1]] ]
        
        vector<vector<pair<int,int>>>adj(n);
        
        for(auto x:conn){
            adj[x[0]].push_back({x[1],1}); //real edge
            adj[x[1]].push_back({x[0],-1}) ; //false edge
        }
        
        vector<bool>vis(n,0);
        
        int c=0;
        dfs(adj,conn,0,c,vis);
        return c;
    }
};