class Solution {
public:
  
   void func(int idx,vector<int>& c,int t,vector<vector<int>>&ans,vector<int>&sub){
        if(idx==c.size()){
            if(t==0)
                ans.push_back(sub);
            return;
        }
    
        if(c[idx]<=t){
            sub.push_back(c[idx]);
            
            func(idx,c,t-c[idx],ans,sub);
            sub.pop_back();
        }
        
        func(idx+1,c,t,ans,sub);
        
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        
        vector<vector<int>>ans;
        vector<int>sub;
        
        func(0,c,t,ans,sub);
        
        return ans;
    }
};