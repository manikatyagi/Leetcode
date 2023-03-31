class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        long long ans=0;
        
        int j=0;
        
        unordered_set<long long>se;
        
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            
            while(j<i and (se.count(nums[i]) or se.size()>=k)){
                sum-=nums[j];
                se.erase(nums[j]);
                j++;
            }
            
            sum+=nums[i];
            se.insert(nums[i]);
            
            if(se.size()==k){
                ans=max(ans,sum);
            }
        }
        return ans;
       
    }
};