class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
           // if(sum-goal==0)ans++;
            
            if(mp.find(sum-goal)!=mp.end()){
                ans+=mp[sum-goal];
            }
            
            
            mp[sum]++;
        }
       return ans;
    }
};