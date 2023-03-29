class MinStack {
public:
    // val, min 
    stack<long long>st;
    long long mini=INT_MAX;
    MinStack() {
     }
    
    void push(int val) {                 // -2 0 -4
        long long v=val;
        if(st.empty()){
            mini=v;
            st.push(v);
        }
        
        else{
            if(v<mini){
                st.push(2* v * 1LL - mini);
                mini=v;
                
            }
            else
                st.push(v);
        }
    }
    
    void pop() {
       if(st.empty())return ;
        
        long long v=st.top();
        st.pop();
        if(v<mini){
            mini=2* mini - v;
        }
    }
    
    int top() {
        if(st.empty())return -1;
        
        long long v=st.top();
        
        if(v<mini)
            return mini;
       
        return v;
    }
    
    int getMin() {
       return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */