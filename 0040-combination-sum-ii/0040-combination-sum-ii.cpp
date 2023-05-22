class Solution {
public:
    // tc= 2^k *k
    void func(int idx,vector<int>& c,int t, vector<vector<int>>&ans, vector<int>&v){
           if(t==0){
               ans.push_back(v);
               return ;
           }
        for(int i=idx;i<c.size();i++){
            
            if(i>idx and c[i]==c[i-1])continue;
    
            if(c[i]>t)break;
            v.push_back(c[i]);
            func(i+1,c,t-c[i],ans,v);
            v.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(), c.end());
        vector<vector<int>>ans;
        vector<int>v;
        
        func(0,c,t,ans,v);
        return ans;
        
    }
};