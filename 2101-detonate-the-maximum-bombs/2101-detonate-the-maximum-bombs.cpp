class Solution {
public:
    int dfs(int curr,vector<vector<int>>& bombs,vector<int>&vis){
       
        vis[curr]=1;
        int x=bombs[curr][0];
        int y=bombs[curr][1];
        int r=bombs[curr][2];
        int c=1;
        for(int i=0;i<bombs.size();i++){
            
            long long x1=abs(x-bombs[i][0]);
            x1*=x1;
            
            long long y1=abs(y-bombs[i][1]);
            y1*=y1;
            
            double dis=sqrt(x1+y1);
            
            if(dis<=r and vis[i]==0){
            
               c+= dfs(i,bombs,vis);
            }
        }
        return c;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n=bombs.size();
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
           vector<int>vis(n,0);
            if(vis[i]!=1){
                
                ans=max(ans,dfs(i,bombs,vis));
            }
         
            
        }
        return ans;
    }
};