class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>pq;
        
        for(int i:nums)
            mp[i]++;
        
        for(auto i:mp){
            pq.push({i.second,i.first});  // 1-3  2-2  3-1
        }
        
        vector<int>ans;
        
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
            
        return ans;
    }
};