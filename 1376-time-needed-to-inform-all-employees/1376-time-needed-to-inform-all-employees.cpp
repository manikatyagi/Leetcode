class Solution {
public:
    int dfs(int curr, vector<int>adj[],vector<int>& info){
         
        int ans=0;
        for(int it:adj[curr]){
           ans=max(ans,dfs(it,adj,info));
        }
        ans+=info[curr];
        
        return ans;
        
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& info) {
        
        vector<int>adj[n];
        //[[] [] [0 1 3 4 5] [] [] []]
        // 0   0    1         0  0  0
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(manager[i]==-1)continue;
            
            adj[manager[i]].push_back(i);
        }
       
        return  dfs(headID,adj,info);
    }
};