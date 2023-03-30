class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        stack<char>s2;
        
        
        for(int i=0;i<s.size();i++){
            if(!s1.empty() and s[i]=='#'){
                s1.pop();
            }
            else if(s[i]!='#'){
                s1.push(s[i]);         // f
            }
        }
        
        for(int i=0;i<t.size();i++){
            if(t[i]=='#' and !s2.empty()){
                s2.pop();
            }
            else if(t[i]!='#'){
                s2.push(t[i]);      // f
            }
        }
        cout<<s1.size()<<" ";
        cout<<s2.size()<<" ";
        if(s1.size()!=s2.size())return false;
        
       while(!s1.empty() and !s2.empty()){
           cout<<s1.top()<<" ";
           cout<<s2.top()<<" ";
          if(s1.top()!=s2.top())return false;
           s1.pop();
           s2.pop();
       }
  
      
        
        return true;
       
        
    }
};