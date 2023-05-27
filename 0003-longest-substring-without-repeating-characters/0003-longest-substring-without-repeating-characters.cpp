class Solution {
public:
    int lengthOfLongestSubstring(string s){
       unordered_set<char>se;
        
        int i=0,j=0;
        int ans=0;
        while(i<s.size()){
            
            if(se.find(s[i])==se.end()){
                se.insert(s[i]);
                ans=max(ans,i-j+1);
                i++;
            }
            else{
                se.erase(s[j]);
                j++;
            }
        }
        return ans;
    }
};