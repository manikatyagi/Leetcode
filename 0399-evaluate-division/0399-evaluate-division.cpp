class Solution {
public:
    
    unordered_map<string,vector<pair<string,double>>>mp;
    void dfs(string src , string dest, double& ans,double temp, unordered_set<string>&vis){
        
        if(vis.find(src)!=vis.end())return ;
        
        vis.insert(src);
        
        if(src==dest){
            ans=temp;
            return ;
        }
        
        for(auto x:mp[src]){
          dfs(x.first,dest,ans,temp*x.second,vis);
            
        }
    
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        // a->b  
        for(int i=0;i<equations.size();i++){
            mp[equations[i][0]].push_back({equations[i][1],values[i]});
            mp[equations[i][1]].push_back({equations[i][0],1.0/values[i]});  
        }
        vector<double>v;
        
        for(auto q:queries){
            string dividend=q[0];
            string divisor=q[1];
            unordered_set<string>vis;
            double ans=-1.0;
            double temp=1.0;
            if(mp.find(dividend)==mp.end() or mp.find(divisor)==mp.end()){
                v.push_back(-1.0);
            }
            else {
                dfs(dividend,divisor,ans,temp,vis);
                v.push_back(ans);
            }
            
            
        }
        return v;
    }
};