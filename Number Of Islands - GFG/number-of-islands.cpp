//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

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
    
   void unionBySize(int u,int v){
        u = findUpar(u);
        v = findUpar(v);

        if(u == v) return;

        if(size[u] < size[v]){
            parent[u] = v;
            size[v] += size[u];
        }
        else{
            parent[v] = u;
            size[u] += size[v]; 
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        DisjointSet ds(n*m);
        
        vector<int>ans;
        int dirc[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        int c=0;
        for(auto it:operators){
           
           int u=it[0];
           int v=it[1];
           
           if(vis[u][v]==1){
               ans.push_back(c);
               continue;
           }
           
           vis[u][v]=1;
           c++;
           for(int i=0;i<4;i++){
               int newr=u+dirc[i][0];
               int newc=v+dirc[i][1];
               
               if(newr>=0 and newr<n and newc>=0 and newc<m and vis[newr][newc]==1){
                 
                   int node=u*m+v;
                   int newnode=newr*m+newc;
                   
                   
                   if(ds.findUpar(node)!=ds.findUpar(newnode)){
                       c--;
                       ds.unionBySize(node,newnode);
                   }
               }
           }
           
           
           
           ans.push_back(c);
           
       }
       return ans;
    }
    
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends