class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>v;
        if(n==1)v.push_back(0);
        
        vector<int>indeg(n);
        
        vector<vector<int>>adj(n);
        
        // [[3] [3] [3] [0 1 2 4] [3 5] [4]]
        
        // indeg= [1 1 1 4 2 1]
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            
            indeg[it[0]]++;
            indeg[it[1]]++;
        }
      
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indeg[i]==1){
                q.push(i);  // 0 1 2 5
                indeg[i]--;
            }
        }
        
        while(!q.empty()){
           
            v.clear();
            int s=q.size();
            
            while(s-->0){
                int node=q.front();  // 0
                q.pop();
                v.push_back(node);
                
                for(auto it:adj[node]){
                    indeg[it]--;
                    
                    if(indeg[it]==1)q.push(it);
                }
                
            }
        }
       return v;
    }
};