class BrowserHistory {
public:
    
    vector<string>b;
    int idx=0;
    BrowserHistory(string homepage) {
        b.push_back(homepage);
        
    }
    
    void visit(string url) {
       idx++;
        if(idx<=b.size()-1){
            b[idx]=url;
            b.resize(idx+1);
            
        }
        else b.push_back(url);
    }
    
    string back(int steps) {
        idx=idx-steps;
        
        if(idx<0)idx=0;
        
        return b[idx];
    }
    
    string forward(int steps) {
      idx=idx+steps;
        if(idx>b.size()-1)idx=b.size()-1;
        
        return b[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */