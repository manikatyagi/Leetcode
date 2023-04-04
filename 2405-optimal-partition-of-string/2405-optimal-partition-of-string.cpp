class Solution {
public:
    int partitionString(string s) {
        
        unordered_set<char>se;
        int c=1;
        string str="";
        
        int r=0,l=0;
        
        while(r<s.size()){
            
            if(se.find(s[r])==se.end()){
                se.insert(s[r]);
                r++;
            }
            else{
                se.clear();
                c++;
            }
        }
        return c;
    }
}; // s  sabc  acs  s s s