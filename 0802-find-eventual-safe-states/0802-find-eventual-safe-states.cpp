class Solution {
public:
   
  
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<vector<int>>rev_graph(n);
        
        for(int i=0;i<n;i++){
            
            for(int it:graph[i]){
                rev_graph[it].push_back(i);
            }
        }
        
        vector<int>indeg(n);
        
        for(int i=0;i<n;i++){
            for(auto it:rev_graph[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)
                q.push(i);
                
        }
        vector<int>ans;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            
            for(int it:rev_graph[f]){
                indeg[it]--;
                
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};