class Solution {
public:
    bool dfs(vector<int>&vis,vector<int>&order,vector<vector<int>>&adj,int curr){
        vis[curr]=1;
        order[curr]=1;
        
        for(auto x:adj[curr]){
            if(!vis[x]){
                bool c=dfs(vis,order,adj,x);
                
                if(c==true)return true;
            }
            
            else if(order[x]==1)return true;
        }
        order[curr]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>vis(numCourses,0);
        vector<int>order(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                bool c=dfs(vis,order,adj,i);
                
                if(c==true)return false;
            }
        }
        return true;
    }
};