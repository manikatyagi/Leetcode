class Solution {
public:
    int partitionString(string s) {
        
        vector<int>last_seen(26,-1);
        int new_patition_idx=0;
        int pat=1;
        for(int i=0;i<s.size();i++){
            
            if(last_seen[s[i]-'a']>=new_patition_idx){
                pat++;
                new_patition_idx=i;
            }
            
            last_seen[s[i]-'a']=i;
        }
        return pat;
    }
}; 