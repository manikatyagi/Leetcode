class Solution {
public:
    int calculate(string s) {
        // bodmas
        
        s+='+';
        stack<int>st;
        char sign='+';
        long long curr=0;
        for(int i=0;i<s.size();i++){
    
            if(isdigit(s[i]))
                curr=curr*10+(s[i]-'0');
            
            
          else if(s[i]=='+' or s[i]=='-' or s[i]=='/' or s[i]=='*'){
              if(sign=='+')
                st.push(curr);
            
            
            else if(sign=='-')
                st.push(curr*(-1));
            
            
            else if( sign=='*'){
                int t=st.top();
                st.pop();
                st.push(t*curr);
            }
            else if (sign=='/'){
                 int t=st.top();
                 st.pop();
                 st.push(t/curr);
            }
             sign=s[i];
             curr=0;
          }       
                
        }
       
        long long int ans=0;
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};