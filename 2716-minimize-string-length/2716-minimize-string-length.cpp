class Solution {
public:
    
    int minimizedStringLength(string s) {
        
      set<char>se;
        
        for(int i=0;i<s.size();i++)
            se.insert(s[i]);
        
        return se.size();
        
    }
};