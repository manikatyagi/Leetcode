
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        
        vector<int>ans;
        
        map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            
            if(i>=k-1){
                if(i>=k) mp[nums[i-k]]--;
                int sum=0;
                int t=0;
                for(auto e:mp){
                    sum+=e.second;
                        
                    if(sum>=x){
                        t=e.first<0?e.first:0;
                        break;
                    }
                }
                ans.push_back(t);   
            }
        }
        return ans;
    }
};