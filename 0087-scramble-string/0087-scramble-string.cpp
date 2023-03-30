class Solution {
public:
    unordered_map<string,bool>mp;
    
    bool solve(string s1,string s2){
        
        if(s1.size()==s2.size() and s1==s2)return true;
        
        string key=s1+s2;
        
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        
        // checking frequency of each char if it is not same so it can't be scramble
        int n=s1.size();
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        for(int i=0;i<s1.size();i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
            
        }
        
        if(v1!=v2){
            return mp[key]=false;
        }
        
        // checking for partition at each point , points will be n-1
        
        for(int i=1;i<n;i++){
            
            if((solve(s1.substr(0,i),s2.substr(0,i)) and solve(s1.substr(i),s2.substr(i)))or (solve(s1.substr(0,i), s2.substr(n-i)) and solve(s1.substr(i),s2.substr(0,n-i))))
                return mp[key]=true;
        }
        
        return mp[key]=false;
        
    }
    bool isScramble(string s1, string s2) {
        
        return solve(s1,s2);
    }
};