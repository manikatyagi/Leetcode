class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 2,3,1,2,4,3   
        // sliding window
        int i=0,j=0;
        int sum=0;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
            while(sum>=target){
                ans=min(i-j+1,ans);
                sum-=nums[j];
                j++;
            }
        }
        
        return ans==INT_MAX?0:ans;
    }
}; 