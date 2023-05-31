class Solution {
public:
    string minWindow(string s, string t) {
       
       if(s.size()<t.size())return "";
        
        unordered_map<char,int>mp;
        
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        
        int count=mp.size();
        int j=0;
        int len=INT_MAX;
        int st=0;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])){
               mp[s[i]]--;
                
                if(mp[s[i]]==0)count--;
            }
          
            
            if(count==0){
                
                 if(len>i-j+1){
                    len=i-j+1;
                     st=j;
                }
                
                while(count==0){
                    
                    if(mp.count(s[j])){
                        mp[s[j]]++;
                        
                        if(mp[s[j]]==1)count++;
                         if(len>i-j+1){
                            len=i-j+1;
                           st=j; 
                        }
                
                    }
                    j++;
                }
               
            }
        }
        
        
        if(len==INT_MAX)return "";
        
        return s.substr(st,len);
        
    }
};