class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
      
        long long p=1;
         p = p << k;
        
        int n=nums.size();
        
        vector<int>pre(n+1,0);
        vector<int>suf(n+1,0);
        pre[0]=0;
        suf[n]=0;
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]|nums[i]; // 0 12 13
        }
        
        
        for(int i=n-1;i>=0;i--){
            suf[i]=suf[i+1]|nums[i]; //  13 9 0
        }
        
       long long ans=0;
        for(int i=0;i<n;i++){
            cout<<ans;
            ans=max(ans,pre[i]|(p*nums[i])|suf[i+1]);
        }
        return ans;
        
    }
};