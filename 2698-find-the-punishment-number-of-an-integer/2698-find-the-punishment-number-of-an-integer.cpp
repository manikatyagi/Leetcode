class Solution {
public:
    
    bool check(string s,int target,int idx){
       if(idx==s.size()){
           if(target==0)return true;
           
           else 
               return false;
       }
          
        if (target < 0)
            return false;
        
        
        for(int i=idx;i<s.size();i++){
            
            string left=s.substr(idx,i+1-idx);
            
            int ln=stoi(left);
            
            if(check(s,target-ln,i+1))return true;
            
        }
          
       return false;
    }
    int punishmentNumber(int n) {
        int ans=0;
       for(int i=1;i<=n;i++){
           
           int t=i*i;
           
           string sq=to_string(t);
           int l=sq.size();
           if(check(sq,i,0)){
               ans+=t;
           }
       }
        return ans;
    }
};