class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)    {
        
        vector<vector<int>>adj[n];
        
        // [[1 100], [[2,100],[3,600]] , [[3,200],[0 ,100]] []]
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,pair<int,int>>>q;
        
        //stops,node,cost
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        q.push({0,{src,0}});
        
        while(!q.empty()){
            
            auto it=q.front();
            
            int node=it.second.first;
            int cost=it.second.second;
            int stops=it.first;
            
            q.pop();
            
            if(stops>k)break;
            
            for(auto x:adj[node]){
                int adjNode=x[0];
                int edgeW=x[1];
                
                if(dist[adjNode]>edgeW+cost and stops<=k){
                    dist[adjNode]=edgeW+cost;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        
        
        if(dist[dst]==INT_MAX)return -1;
        
        return dist[dst];
    }
};