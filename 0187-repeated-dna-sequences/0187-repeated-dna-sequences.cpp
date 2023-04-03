class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string>v;
        unordered_map<string,int>mp;
        string t="";
        int l=0;
        for(int i=0;i<s.size();i++){
            t+=s[i]; // AAAACCCCC
            
            if(t.size()==10){
                mp[t]++;
             //   cout<<t<<" ";
                t=t.erase(0,1);
                
           
            }
        }
        
        for(auto i:mp){
            if(i.second>1){
                v.push_back(i.first);
            }
        }
        return v;
    }
};