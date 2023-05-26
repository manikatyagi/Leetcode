class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
     
        int j=0;
        
        int c=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                
                while(c==k and j<=i){
                    
                    if(nums[j]==0){
                        c--;
                    }
                    
                    j++;
                }
                
                c++;
            }
            
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};