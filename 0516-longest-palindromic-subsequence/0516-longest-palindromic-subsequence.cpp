class Solution {
public:
    
    int lcs(string s,string t){
        int l=s.size();
        int dp[l+1][l+1];
        
        
        for(int i=0;i<=l;i++){
             dp[0][i]=0;
             dp[i][0]=0;
        }
           
        
        for(int i=1;i<=l;i++){
            
            for(int j=1;j<=l;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[l][l];
    
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        
        return lcs(s,t);
    }
};