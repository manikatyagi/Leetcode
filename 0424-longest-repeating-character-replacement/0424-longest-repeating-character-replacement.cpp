class Solution {
public:
    int characterReplacement(string s, int k) {
         //AABABBA
         //iii
        unordered_map<char,int>mp;
        
        int i=0,j=0,ans=0,res=0;
        
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            ans=max(ans,mp[s[i]]);
            
            if(i-j+1-ans>k){
                mp[s[j]]--;
                j++;
           
            }
            
            res=max(ans,i-j+1);
        }
        
        return res;
    }
};