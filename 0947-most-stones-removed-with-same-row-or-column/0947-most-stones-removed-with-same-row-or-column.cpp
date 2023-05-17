
class Solution {
public:
    void dfs(int idx, vector<vector<int>>& stones,vector<int>&vis ,int n){
        vis[idx]=1;
        
        for(int i=0;i<n;i++){
            
            if(vis[i]==0 and (stones[i][0]==stones[idx][0] or stones[i][1]==stones[idx][1])){
                dfs(i,stones,vis,n);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        
        int n= stones.size();
        
        vector<int>vis(n,0);
        int c=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,stones,vis,n);
                c++; // 1   
            }
        }
        return n-c;
    }
};