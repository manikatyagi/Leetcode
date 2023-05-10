class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        
        vector<vector<int>>adj(numCourses);
        
         for(auto it:prerequisites){
                adj[it[1]].push_back(it[0]);
            }
        
        vector<int>indeg(numCourses,0);
        
        queue<int>q;
        
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        
        
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
               // ans.push_back(i);
            }
        }
        
        while(!q.empty()){
            int f=q.front();
            q.pop();
            
            ans.push_back(f);
            
            for(auto i:adj[f]){
                indeg[i]--;
                
                if(indeg[i]==0){
                    q.push(i);
                }
            }
        }
        
         if (ans.size()==numCourses)return ans;
        return {};
    }
};