
class DisjointSet{
    public:  
    vector<int>parent,rank,size;
   
      DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
            
        }
    }
    
    int findUpar(int node){
        if(node==parent[node])return node;
        
        return parent[node]=findUpar(parent[node]);
    }
    
    void unionByRank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        
        if(ulp_u==ulp_v)return ;
        
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]>rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
            
            
        }
        
    }
    
    void unionBySize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        
        if(ulp_u==ulp_v)return ;
        
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=ulp_u;
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=ulp_v;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mp;
        
        int n=accounts.size();
        
        DisjointSet ds(n);
        
        for(int i=0;i<n;i++){
            
            for(int j=1;j<accounts[i].size();j++){
                
                if(!mp.count(accounts[i][j])){   // mail - idx
                    mp[accounts[i][j]]=i;
                }
                else{
                    int t=mp[accounts[i][j]];
                    
                    ds.unionByRank(t,i);
                }
            }
        }
        
       vector<string>merge[n];
        
       for(auto it:mp){
           string mail=it.first;
           int node=ds.findUpar(it.second);
           
           merge[node].push_back(mail);
       }
        
        vector<vector<string>>ans;
        
        for(int i=0;i<n;i++){
            
            if(merge[i].size()==0)continue;
            
            else {
                sort(merge[i].begin(),merge[i].end());
               vector<string>temp;
                temp.push_back(accounts[i][0]);
                
                for(string s:merge[i]){
                    temp.push_back(s);
                }
                
                ans.push_back(temp);
            }
                
        }
        return ans;
        
    }
};