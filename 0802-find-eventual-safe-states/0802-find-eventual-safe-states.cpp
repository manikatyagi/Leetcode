class Solution {
public:
   
    bool dfs(int curr, vector<int>&vis, vector<int>&order,vector<int>&safe,vector<vector<int>>& graph){
        vis[curr]=1;
        order[curr]=1;
        
        for(auto it:graph[curr]){
            
            if(vis[it]==0){
                if(dfs(it,vis,order,safe,graph))
                    return true;
            }
            
            else if(order[it]==1)return true;
        }
        
        safe[curr]=1;
        order[curr]=0;
        
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int>vis(n,0);
        vector<int>order(n,0);
        vector<int>safe(n,0);
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,vis,order,safe,graph);
            }
        }
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            if(safe[i]==1)ans.push_back(i);
        }
       return ans; 
    }
};