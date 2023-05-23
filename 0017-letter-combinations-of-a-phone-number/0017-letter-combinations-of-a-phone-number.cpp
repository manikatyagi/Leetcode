class Solution {
public:
    void func(int idx,string digits,unordered_map<char,string>mp,vector<string>&v,string s){
        
        if(idx>=digits.size()){
            v.push_back(s);
            return;
        }
        
        string val=mp[digits[idx]];
        
        for(int i=0;i<val.size();i++){
            s.push_back(val[i]);
            func(idx+1,digits,mp,v,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>v;
        if(digits.size()==0)return v;
        unordered_map<char,string>mp;
        
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
       
        string s="";
        
        func(0,digits,mp,v,s);
        
        return v;
    }
};