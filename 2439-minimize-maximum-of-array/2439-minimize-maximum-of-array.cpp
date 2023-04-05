class Solution {
public:
    bool check(vector<int>& nums, int m){
       
        long long prev=nums[0];
        
        if(prev>m)return false;
      
        for(int i=1;i<nums.size();i++){
           long long diff=m-prev;
            prev=nums[i]-diff;
            
            if(prev>m)return false;
            
        }
        
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        
        
        int low=0;
        
        int high=INT_MAX;
        for(int i=0;i<nums.size();i++){
            high=max(high,nums[i]);
        }
        //3,7,1,6
        // m-
        int ans=0;
        while(low<high){
            
            int mid=low+(high-low)/2;
            
            if(check(nums,mid)){
                ans=mid;
                high=mid;
            }
            else
                low=mid+1;
        }
      return ans;  
    }
};