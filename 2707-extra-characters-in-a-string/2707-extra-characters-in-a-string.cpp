class Solution {
public:
    int func(string s,unordered_map<string,int>&mp,int idx,vector<int>&dp){
        
        if(idx>=s.size())return 0;
        
        if(dp[idx]!=-1)return dp[idx];
        
        int minExtr=s.size();
        
        string currStr="";
        
        for(int i=idx;i<s.size();i++){
            currStr.push_back(s[i]);
            
            int currExtr=mp.count(currStr)?0:currStr.size();
            
            int nextExtr=func(s,mp,i+1,dp);
            int totExtr=currExtr+nextExtr;
            
            minExtr=min(totExtr,minExtr);
        }
        dp[idx]=minExtr;
        
       return dp[idx]; 
    }
    int minExtraChar(string s, vector<string>& dic) {
        vector<int>dp(s.size(),-1);
        unordered_map<string,int>mp;
        
        for(string st:dic){
            mp[st]++;
        }
        
        return func(s,mp,0,dp);
    }
};