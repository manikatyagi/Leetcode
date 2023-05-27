class Solution {
public:
    int subArrayatMostK(vector<int>& nums, int k){
        
        int i=0,j=0;
        int c=0;
        
        int ans=0;
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]%2==1){
                c++;
            }
            
            while(c>k){
                if(nums[j]%2==1)c--;
                
                j++;
            }
            ans+=i-j+1;
        }
            
        return ans;
        
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return subArrayatMostK(nums,k)-subArrayatMostK(nums,k-1);
    }
};