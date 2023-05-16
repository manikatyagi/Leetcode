class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // FLOYD ALGORITHM - multiple source shortes path
        
       vector<vector<int>>cost(n,vector<int>(n,INT_MAX));
        
        for(int i=0;i<n;i++){
            cost[i][i]=0;
        }
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            cost[u][v]=wt;
             cost[v][u]=wt;
        }
        
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                     if(cost[i][via]==INT_MAX || cost[via][j]==INT_MAX) continue;
                    cost[i][j]=min(cost[i][j],cost[i][via]+cost[via][j]);
                }
            }
        }
        
        int temp=n,res=0; 
        for(int i=0;i<n;i++){
            int curr = 0;
            for(int j=0;j<n;j++){
                if(distanceThreshold>=cost[i][j]) curr++; 
            }
            if(temp>=curr){
                temp=curr;
                res=i; 
        }
        }
        return res;
    }
};