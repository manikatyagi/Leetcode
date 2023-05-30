class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        // "ababbbc"  a-2 b-4 c-1
       vector<int>v(3,0);
        
        int n=s.size();
        int j=0;
        for(int i=0;i<n;i++){
            
           v[s[i]-'a']++;
            
            while(v[0]!=0 and v[1]!=0 and v[2]!=0){
                v[s[j]-'a']--;
                j++;
       
            }
            ans+=j;//1 3 6 10
        }
        return ans;
    }
};