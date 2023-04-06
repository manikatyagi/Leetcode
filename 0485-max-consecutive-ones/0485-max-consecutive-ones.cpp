class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int sum=0;
        int ans=0;
        int j=0;
        int psum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]; // 1
            
            if(sum!=psum){
                ans=max(ans,i-j+1);
            }
            else{
                sum=0;
                psum=0;
                j=i+1;
                
            }
            psum=sum; // 1
            
        }
        return ans;
    }
};