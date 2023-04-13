class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int i=0,j=0;
        stack<int>s;
    
       
        for(int i=0;i<pushed.size();i++ ){
            
            s.push(pushed[i]); // 1  2  
            
            while(!s.empty() and s.top()==popped[j]){
                s.pop();  //  
                j++;
            }
        }
       if(j==pushed.size())
          return  true;
          
         else
         return false;
        
    }
};