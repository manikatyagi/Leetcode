class Solution {
public:
    int lengthOfLongestSubstring(string s){
       
       int left=0,right=0;
        int len=0;
        unordered_set<char>se;
        
        while(right<s.size()){
            if(se.find(s[right])==se.end()){
                se.insert(s[right]);
                len=max(len,right-left+1);
                right++;
    
            }
            else{
                se.erase(s[left]);
                left++;
            }
        }
        
        return len;
    }
};