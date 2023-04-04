class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans=INT_MIN;
        // [-3,0,1,-2]
        //   i      j
        if(nums.size()==1)return nums[0];
        int left=1;
        int right=1;
        
        int i=0,j=nums.size()-1;
        while(i<nums.size() and j>=0){
            
            left=left*nums[i]; // -3 0 
            right=right*nums[j];  // -2  -2
          
            int pr=max(left,right);  // -2 0
            
           
            ans=max(ans,pr);  // -2
            i++;
            j--;
            
             if(left==0){
                left=1;
            }
            if(right==0){
                right=1;
            }
       
        }
    
      return ans; 
    }
};