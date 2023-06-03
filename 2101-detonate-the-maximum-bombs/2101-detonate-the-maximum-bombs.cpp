class Solution {
public:
  void dfs(int curr,int& c,vector<int>&vis,vector<int>adj[]){
       vis[curr]=1;
        c++;
        for(auto it:adj[curr]){
            
            if(vis[it]==0){
                
                dfs(it,c,vis,adj);
            }
                
        }
       
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n=bombs.size();
        
        vector<int>adj[n];
        //[[1 2],[] [3] ,[4]]
        for(int i=0;i<n;i++){
             int x=bombs[i][0];
             int y=bombs[i][1];
             int r=bombs[i][2];
            
            for(int j=0;j<n;j++){
                long long x1=abs(x-bombs[j][0]);
                x1*=x1;
            
                long long y1=abs(y-bombs[j][1]);
                 y1*=y1;
            
                 double dis=sqrt(x1+y1);
                     
                 if(dis<=r){
                     adj[i].push_back(j);
                 }
                
            }
             
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
           int c=0;
            vector<int>vis(n,0);
            
            dfs(i,c,vis,adj);
            
            ans=max(ans,c);
            
        }
        return ans;
    }
};