class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,k});
        
        vector<int>dist(n+1,INT_MAX);
        
        vector<vector<int>>adj[n+1];
        // [[] [1 3] [4] []]
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        dist[k]=0;
        dist[0]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            
            pq.pop();
            
            for(auto it:adj[node]){
                int adjNode=it[0];
                int edgeW=it[1];
                
                if(dist[adjNode]>d+edgeW){
                    dist[adjNode]=d+edgeW;
                    
                    pq.push({dist[adjNode],adjNode});
                }
                
            }
            
        }
        int ans=0;
        for(int i=0;i<n+1;i++){
            if(dist[i]==INT_MAX)return -1;
            ans=max(ans,dist[i]);
            
        }
        
        return ans;
    }
};