class Solution {
public:
    int maxVowels(string s, int k) {
       
        int ans=0;
        int c=0;
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                c++;
            }
            
            if(i>=k-1){
                ans=max(ans,c);
                if(s[i-k+1]=='i' or s[i-k+1]=='o' or s[i-k+1]=='u' or s[i-k+1]=='a' or s[i-k+1]=='e'){
                c--;
            }
                
            }
        }
        return ans;
    }
};