class Solution {
public:
   
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int c=count(nums.begin(),nums.end(),1);
        
        if(c!=0)return n-c;
        int ans=1e7;
        for(int i=0;i<n;i++){
            int g=nums[i];
            for(int j=i+1;j<n;j++){
                
                g=__gcd(g,nums[j]);
                
                if(g==1){
                    ans=min(ans,j-i+(n-1));
                    break;
                }
            }
        }
        
        return ans==1e7?-1:ans;
    }
};