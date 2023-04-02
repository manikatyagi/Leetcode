class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        //01000111        // 0010
        //       i              i
        int ans=0;
        int i=0;
        while(i<s.size()){
            int zeros=0;
            int ones=0;
            
            while(i<s.size() and s[i]=='0'){
                zeros++;
                i++;
            }
            
            while(i<s.size() and s[i]=='1'){
                ones++;
                i++;
            }
            int len=2*min(zeros,ones);//2 6
            ans=max(ans,len);
        }
        return ans;
    }
};