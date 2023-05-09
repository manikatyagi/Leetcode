class Solution {
public:
    
    void dfs(vector<int>&vis,vector<vector<int>>&adj, int n,int curr){
        vis[curr]=1;
        for(auto x:adj[curr]){
            if(vis[x]==0){
               
                dfs(vis,adj,n,x);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& conn) {
        
        if(conn.size()<n-1)return -1;
        
        vector<vector<int>>adj(n);
        
        for(auto i:conn){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int>vis(n,0);
        
       // dfs(vis,adj,n,0);
        int c=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                c++;
                dfs(vis,adj,n,i);
            }
        }
        return c-1;
    }
};