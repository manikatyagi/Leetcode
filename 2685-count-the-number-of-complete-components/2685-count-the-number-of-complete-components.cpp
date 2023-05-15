class Solution {
public:
    void dfs(int curr, vector<vector<int>>&graph, vector<int>&vis,int &nodes,int &edges){
        vis[curr]=1;
        nodes++;//2 3
        edges+=graph[curr].size(); //4 6
        
        for(int it:graph[curr]){
            if(vis[it]==0){
                dfs(it,graph,vis,nodes,edges);
            }
        }
        
        
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        // for complete components number of edges in the component is equal to m*(m-1)/2, where m is the number of nodes in the component.
        
        // [[1 2] [0 2] [0 1] [4] [3] []]
        
        vector<vector<int>>graph(n);
        
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            int nodes=0;
            int edges=0;
            if(vis[i]==0){
                dfs(i,graph,vis,nodes,edges);
            
               //edges=edges/2;
            
               if(nodes*(nodes-1)==edges)ans++;
            }
            
        }
        return ans;
    }
};