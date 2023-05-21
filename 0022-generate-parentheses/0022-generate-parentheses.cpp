class Solution {
public:
    void func(string str,int n,int open,int close,vector<string>&v){
        if(str.size()==n*2){
            v.push_back(str);
        }
        
        if(open<n)func(str+'(',n,open+1,close,v);
        
        if(close<open)func(str+')',n,open,close+1,v);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        string s="";
        
        func(s,n,0,0,v);
        return v;
    }
};