class Solution {
public:
   
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      
        vector<vector<int>>adj(n);// 0     1   2    3     4     5
        // [[1 2] [2 0] [0 1]]  // [[1 2] [0] [0] [4 5] [3 5] [3 4]]
        
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);   
        }
        
        // 0 1
        queue<int>q;
        
        q.push(source);
        vector<int>vis(n,0);
        
        while(!q.empty()){
            int f=q.front();
            
            q.pop();
            
            if(f==destination)return true;
            
            for(auto x:adj[f]){
                if(vis[x]==0){
                    vis[x]=1;
                    q.push(x);
                }
            }
        }
       return false;
    }
};