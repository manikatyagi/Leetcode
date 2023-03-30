class Solution {
public:
    int calPoints(vector<string>& op) {
        
        stack<int>st;
        
        for(int i=0;i<op.size();i++){
            
            if(op[i]=="D"){
                int t=st.top();
                
                st.push(t*2);
            }
            
            else if(op[i]=="C"){
                st.pop();
            }
            
            else if(op[i]=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                
                st.push(b);
                st.push(a);
                
                st.push(a+b);
            }
            
            else{
                int t=stoi(op[i]);
                st.push(t);
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};