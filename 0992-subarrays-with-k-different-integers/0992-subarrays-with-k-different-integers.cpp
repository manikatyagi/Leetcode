class Solution {
public:
    int subarray(vector<int>& nums, int k){
        unordered_map<int,int>mp;
        int j=0;
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            
            mp[nums[i]]++;
            
            while(mp.size()>k){
                mp[nums[j]]--;
                
                if(mp[nums[j]]==0)mp.erase(nums[j]);
                
                j++;
            }
            
            count+=i-j+1;
            
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       
        return subarray(nums,k)-subarray(nums,k-1);
    }
};