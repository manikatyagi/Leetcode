class Solution {
public:
    unordered_map<string ,bool>mp;
    bool wordBreak(string s, vector<string>& wordDict) {
       if(find(wordDict.begin(),wordDict.end(),s)!=wordDict.end())
           return true;
        
       
        if(mp.find(s)!=mp.end())
           return mp[s];
        
       
        for(int i=0;i<s.size();i++){
            string sub=s.substr(0,i+1);
            if(find(wordDict.begin(),wordDict.end(),sub)!=wordDict.end() and wordBreak(s.substr(i+1),wordDict)){
                mp[s]=true;
                
                return true;
            }
                
        }
        
        mp[s]=false;
        
        return false;
    }
};