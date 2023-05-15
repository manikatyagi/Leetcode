class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
         int n=heights.size();
        int m=heights[0].size();
        
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        
      
        int dirc[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        int diff=0;
        pq.push({0,{0,0}});
        int ans=99999;
        while(!pq.empty()){
            int effort=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==n-1 and j==m-1)return effort;
            
            for(int k=0;k<4;k++){
                int r=i+dirc[k][0];
                int c=j+dirc[k][1];
              
                if(r>=0 and c>=0 and r<n and c<m){
                     int diff=max(effort,abs(heights[i][j]-heights[r][c]));
                     if(diff<dis[r][c]){
                         dis[r][c]=diff;
                          pq.push({diff,{r,c}});
                     }
                   
                }
            }
        }
        return ans;
    }
};