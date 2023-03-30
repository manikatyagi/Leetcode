class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int i=s.size()-1;
        int j=t.size()-1;
        int back;
        while(true){
            
             back=0;
            
            while(i>=0 and (back>0 or s[i]=='#')){
                if(s[i]=='#'){
                    back++;
                }
                else{
                    back--;
                }
                i--;
            }
            
            back=0;
            
            while(j>=0 and (back>0 or t[j]=='#')){
                if(t[j]=='#'){
                    back++;
                }
                else{
                    back--;
                }
                j--;
            }
            
            if(i>=0 and j>=0 and s[i]==t[j]){
                i--;
                j--;
            }
            else
                break;
        }
      
        return i==-1 and j==-1;
    }
};