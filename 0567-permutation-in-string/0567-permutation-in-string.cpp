class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
      vector<int>fs1(26,0);
        vector<int>fs2(26,0);
        
        vector<int>v;
        int l=0;
        
        for(int i=0;i<s1.size();i++){
            
            fs1[s1[i]-'a']++;
        }
        
        for(int i=0;i<s2.size();i++){
            fs2[s2[i]-'a']++;
            
            
            if(i>=s1.size()-1){
                if(fs1==fs2){
                   return true;
                  
                }
                 fs2[s2[l]-'a']--;
                 l++;
                
            }
            
        }
         
      return false; 
    }
};