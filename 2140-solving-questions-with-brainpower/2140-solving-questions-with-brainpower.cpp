class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n+1,0);
        
        //0 1 2 3 4 5
       // 
        
        for(int i=n-1;i>=0;i--){
            int future=questions[i][1]+i+1;//
            
            if(future>=n)dp[i]=questions[i][0];
            
            else dp[i]=questions[i][0]+dp[future];
            
            dp[i]=max(dp[i],dp[i+1]);
        }
        return dp[0];
    }
};