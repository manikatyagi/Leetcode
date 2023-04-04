class Solution {
public:
   
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>fp(26,0);
        vector<int>fs(26,0);
        
        vector<int>v;
        int l=0;
        
        for(int i=0;i<p.size();i++){
            
            fp[p[i]-'a']++;
        }
        
        for(int i=0;i<s.size();i++){
            fs[s[i]-'a']++;
            
            
            if(i>=p.size()-1){
                if(fs==fp){
                    v.push_back(l);
                  
                }
                 fs[s[l]-'a']--;
                 l++;
                
            }
            
        }
         
      return v;  
    }
};