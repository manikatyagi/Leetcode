class Solution {
public:
    void dfs(vector<int> adj[], vector<bool>&vis ,int node){
        vis[node]=1;
        
        for(auto x:adj[node]){
            if(!vis[x]){
                dfs(adj,vis,x);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& conn) {
        // adj matrix 
        //    0        1     2     3    4   5 
        // [[1,2 3] [0 2 3] [0 1] [0 1] [] []]
        vector<int>adj[n];
        
        for(auto v:conn){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);  
        }
        //  0 1 2 3 4 5
        // [0 0 0 0 0 0]
        vector<bool>vis(n,0);
        
        int c=0;
        int m=conn.size();
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++;    // 1
                dfs(adj,vis,i);
            }
        }
        
        if(m>=n-1)return c-1;
        
        return -1;
    }
};