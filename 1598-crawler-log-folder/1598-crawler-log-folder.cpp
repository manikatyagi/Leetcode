class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        stack<string>st;
        
        for(int i=0;i<logs.size();i++){
            
            if(!st.empty() and logs[i]=="../"){
                st.pop();
            }
            
            
            else if(logs[i]!="./" and logs[i]!="../"){
                st.push(logs[i]);
            }
        }
        return st.size();
    }
};