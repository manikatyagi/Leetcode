class Solution {
public:
    string longestNiceSubstring(string s) {
        
        if(s.size()<2)return "";
        
        unordered_set<char>se;
        int n=s.size();
       se.insert(s.begin(),s.end()); // YaAzy
        
        
        for(int i=0;i<s.size();i++){
            
            char u=toupper(s[i]);  
            char l=tolower(s[i]); 
            if(se.find(u)==se.end() or se.find(l)==se.end()){
               string s1=longestNiceSubstring(s.substr(0,i));
               string s2=longestNiceSubstring(s.substr(i+1));
                
                return s1.size()>=s2.size()?s1:s2;
                
            }
            
        }
        return s;
        
    }
}; 