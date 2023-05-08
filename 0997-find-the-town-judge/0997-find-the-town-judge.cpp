class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>mp;
       
       for(auto i:trust){
           mp[i[0]]=i[1]; // 1-3  1-4  2-3  2-4  4-3  
       } 
        int ans=-1;
        int c=0;
        for(int i=1;i<=n;i++){
            if(mp[i]==0){
                ans=i;
                c++;
            }
        }
        
        if(c>1)return -1;
        c=0;
        for(auto i:trust){
            if(i[1]==ans){
                c++;
            }
        }
        
        if(c==n-1)return ans;
        
        return -1;
        
    }
};