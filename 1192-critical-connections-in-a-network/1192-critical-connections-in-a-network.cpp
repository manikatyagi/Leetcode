class Solution {
public:
    int timer=1;
    
    void dfs(int node,int parent,vector<int>&vis,vector<int>graph[],vector<int>&tin , vector<int>&low,vector<vector<int>>&ans){
        
        vis[node]=1;
        
        tin[node]=low[node]=timer;
        
        timer++;
        
        for(auto it:graph[node]){
            if(it==parent)continue;
            
            if(vis[it]==0){
                dfs(it,node,vis,graph,tin,low,ans);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node]){
                    ans.push_back({it,node});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int>graph[n];
        
        for(auto it:connections){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        vector<int>vis(n);
        vector<vector<int>>ans;
        vector<int>tin(n);
        vector<int>low(n);
        
        dfs(0,-1,vis,graph,tin,low,ans);
        
        return ans;
        
    }
};