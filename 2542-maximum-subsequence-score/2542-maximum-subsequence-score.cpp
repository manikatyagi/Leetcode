class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // 1 2 3 
        
        // 1-2 3-1 3-3 2-4
        // 1-3, 2-1, 3-3, 4-2
        // 3 3 2 1 
        long long ans=0;
       vector<pair<int,int>>v;
        
        for(int i=0;i<nums1.size();i++){
            v.push_back({nums2[i],nums1[i]});
        }
        
        sort(v.begin(),v.end());
        
       long long sum=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int n=nums2.size();
        for(int i=n-1;i>n-k-1;i--){
            sum+=v[i].second;
            pq.push(v[i].second);
        }
        ans=max(ans,sum*(v[n-k].first));
        
        for(int i=n-k-1;i>=0;i--){
            sum-=pq.top();
            pq.pop();
            sum+=v[i].second;
            pq.push(v[i].second);
            ans=max(ans,sum*(v[i].first));   
        }
        return ans;
    }
};