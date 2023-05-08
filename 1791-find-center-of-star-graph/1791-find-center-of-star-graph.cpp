class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // [[2] [1 3 4] [2] [2]]
        int n =edges.size()+1;

        vector<vector<int>>adj(n+1);
        
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        for(int i=1;i<=n;i++){
            if(adj[i].size()==n-1)return i;
        }
       return -1; 
    }
};