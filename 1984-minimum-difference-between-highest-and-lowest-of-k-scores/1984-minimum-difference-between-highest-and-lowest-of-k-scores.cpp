class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // 1 4 7 9
        // 0 1 2 3
        // k+i-1 2+2-1
        
        if(nums.size()==1)return 0;
        sort(nums.begin(),nums.end());
        
        int ans=INT_MAX;
       
        
        for(int i=0;i<=nums.size()-k;i++){
                     
             int diff=nums[i+k-1]-nums[i];
            
             ans=min(diff,ans);
        }
        return ans;
    }
};