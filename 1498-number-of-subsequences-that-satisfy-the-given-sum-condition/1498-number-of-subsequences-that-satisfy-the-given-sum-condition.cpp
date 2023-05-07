class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
       const int mod=1000000007;
        sort(nums.begin(),nums.end()); // 3 5 6 7  
        int r=nums.size()-1;
        int ans=0;
        vector<int>p(nums.size(),0);
        
        p[0]=1;
        for(int i=1;i<nums.size();i++){
           
            p[i]=(p[i-1]*2)%mod;
           
        }
        int l=0;
        
        while(l<=r){
            
            if(nums[l]+nums[r]<=target){
                ans+=p[r-l];
                ans=ans%mod;
                l++;
            }
            else
                r--;
            
            
        }
        return ans;
    }
};