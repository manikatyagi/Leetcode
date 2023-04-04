class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int ans=0;
        int pr=1;
        int j=0;
        
        for(int i=0;i<nums.size();i++){
            pr=pr*nums[i];  //10  10*6=10
            
            while(pr>=k and j<=i){
                pr=pr/nums[j];
                j++;
            }
            
            ans+=(i-j+1);      // 2+ 3-1+1=5
            
        }
        
      return ans;  
    }
};