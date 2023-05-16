class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long  mod=1e9+7;
        vector<long long>dist(n,LONG_MAX);
        dist[0]=0;
        
        vector<int>ways(n,0);
        ways[0]=1;
        
        vector<vector<long long>>adj[n];
        
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long, int>>>pq;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            long long d=pq.top().first;
            
            long long node=pq.top().second;
            
            pq.pop();
            
            for(auto it:adj[node]){
                long long adjNode=it[0];
                long long edgeW=it[1];
                
                if(dist[adjNode]>d+edgeW){
                    dist[adjNode]=d+edgeW;
                    ways[adjNode]=ways[node];
                    pq.push({dist[adjNode],adjNode});
                }
                else if(dist[adjNode]==d+edgeW){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};