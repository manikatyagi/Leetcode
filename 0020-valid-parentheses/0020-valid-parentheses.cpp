class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        
        for(int i=0;i<s.size();i++){
            
           if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
               st.push(s[i]);
           }
         
            if(!st.empty()){
                
                if(s[i]==')'){
                    if(st.top()=='('){
                        st.pop();
                        continue;
                    }
                    else
                        break;
                }
                
                if(s[i]==']'){
                    if(st.top()=='['){
                        st.pop();
                        continue;
                    }
                    else
                        break;
                }
                
                if(s[i]=='}'){
                    if(st.top()=='{'){
                        st.pop();
                        continue;
                    }
                    else
                        break;
                }
            }
            else
                return false;
        }   
    
            return st.empty()? true:false;
            
        
    }
};