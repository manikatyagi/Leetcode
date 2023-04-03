class Solution {
public:
    int longestSubstring(string s, int k) {
        
        
        unordered_map<char,int>mp;
        
        int n=s.size();
        
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
       int i=0;                          
        while(i<s.size() and mp[s[i]]>=k){             
            i++;                                    
        }
        
        if(i==s.size())return s.size();
        
        
        int left=longestSubstring(s.substr(0,i),k); //ababb
        
        while(i<s.size() and mp[s[i]]<k)
            i++;
        
        int right=i<n? longestSubstring(s.substr(i),k):0 ; // c
        
        
        
        return max(left,right);
    }
};