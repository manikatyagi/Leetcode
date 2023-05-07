class Solution {
public:
    string predictPartyVictory(string senate) {
        
        queue<int>r;
        queue<int>d;
        
        int n=senate.size();
        
        for(int i=0;i<n;i++){
            
            if(senate[i]=='R')r.push(i);
            else d.push(i);
        }
        
        while(!r.empty() and !d.empty()){
            
            if(r.front()<d.front()){
               
                r.push(n++);
            }
            
            else{
                
                d.push(n++);
            }
            
            r.pop(),d.pop();
            
        }
        
        return r.empty()?"Dire":"Radiant";
        
        
    }
};