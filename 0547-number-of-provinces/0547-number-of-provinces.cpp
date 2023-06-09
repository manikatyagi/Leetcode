class Solution {
public:
    void dfs(int node, vector<int>&vis,vector<vector<int>>&graph){
        vis[node]=1;
        
        for(auto it:graph[node]){
            if(!vis[it]){
                dfs(it,vis,graph);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), m = isConnected[0].size();
        vector<vector<int>>graph(n);
        // [[0 1] [0 1] [2]]
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(isConnected[i][j]==1){
                    graph[i].push_back(j);
                }
            }
        }
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                dfs(i,vis,graph);
            }
                
        }
        return ans;
    }
};