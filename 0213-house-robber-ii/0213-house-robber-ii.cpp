class Solution {
public:
    int func(vector<int>nums){
        int n=nums.size();
        vector<int>dp(n+1,0);
	    dp[0]=nums[0];
	    
	    for(int i=1;i<n;i++){
	         int pick=nums[i];
	         if(i>1)pick+=dp[i-2];
	         int notpick=dp[i-1];
	         
	         dp[i]=max(pick,notpick);
	    }
	   
	    return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        vector<int>v;
        vector<int>v1;
        int n=nums.size();
         if(n==0 ) return 0;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=n-1)
             v.push_back(nums[i]);
            
            if(i!=0)
              v1.push_back(nums[i]);
        }
       
       return max(func(v),func(v1));

    }
};