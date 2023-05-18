class Solution {
public:
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int>v;
        
        vector<int>g[n];
        vector<int>vis(n,0);
        
        for(auto it:edges){
            g[it[0]].push_back(it[1]);
        }
        
        // [[1 2] [] [5] [4] [2] []]
        
       vector<int>indeg(n);
        
        for(int i=0;i<n;i++){
             for(auto it:g[i]){
               indeg[it]++;
             }
        }
        
        for(int i=0;i<n;i++){
            if(indeg[i]==0)v.push_back(i);
        }
       return v;
    }
};