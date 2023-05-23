class Solution {
public:
   bool isPalindrom(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }
       
       return true;
    }
    void func(int idx,string s,vector<vector<string>>&ans,vector<string>&v){
        if(idx==s.size()){
            ans.push_back(v);
            return ;
        }
        
        for(int i=idx;i<s.size();i++){
            
            if(isPalindrom(s,idx,i)){
                v.push_back(s.substr(idx,i-idx+1));
                func(i+1,s,ans,v);
                v.pop_back();
            }
            
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>v;
        func(0,s,ans,v);
        return ans;
    }
};