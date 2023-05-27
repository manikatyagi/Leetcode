class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int sum=0;
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]%2==0)nums[i]=0;
            else
                nums[i]=1;
        }
        
        
        for(int i=0;i<nums.size();i++){
            
            sum+=nums[i];
            
            if(sum==k)ans++;
            
            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};