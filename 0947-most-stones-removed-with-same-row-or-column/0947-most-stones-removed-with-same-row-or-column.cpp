
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
   
    int removeStones(vector<vector<int>>& stones) {
        
        int r=0,c=0;
         int n= stones.size();
        for(auto it:stones){
            r=max(r,it[0]);
            c=max(c,it[1]);
        }
       
        
        DisjointSet ds(r+c+1); // row+col
       for(auto it:stones){
           
           int u=it[0];
           int v=it[1]+r+1;
           
           
           ds.unionBySize(u,v);
           
       }
        int comp=0;
        
        for(int i=0;i<r+c+1;i++){
            if(ds.parent[i]==i and ds.size[i]>1)comp++;
        }
        
       return n-comp;
    }
};