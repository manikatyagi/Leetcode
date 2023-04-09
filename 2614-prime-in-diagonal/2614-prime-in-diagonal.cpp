class Solution {
public:
    
    bool check(int num)
    {
     if(num < 2) return false;
    for(int i=2;i*i<=num;i++){
        if(num%i==0)return false;
    }
    return true;  
   }
    int diagonalPrime(vector<vector<int>>& nums) {
        
        
        int ans=0;
        int n=nums.size();
       
        for(int i=0;i<n;i++){
           
            if(check(nums[i][i])){
                ans=max(ans,nums[i][i]);
            }
            
          
            if(check(nums[i][n-i-1])){
                 ans=max(ans,nums[i][n-i-1]);
            }
          
          
        }
        
        
        
        return ans;
    }
};