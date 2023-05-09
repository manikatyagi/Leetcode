//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int>&vis,vector<int> adj[], int par,int curr){
       vis[curr]=1;
       for(auto x:adj[curr]){
           if(!vis[x]){
               if(dfs(vis,adj,curr,x))return true;
           }
           
           else if(x!=par)return true;
       }
       return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
       vector<int>vis(V,0);
       vector<int>order(V,0);
       for(int i=0;i<V;i++){
           if(vis[i]==0){
              
             bool c=dfs(vis,adj,-1,i);
             if(c==true)return true;
           }
       }
       return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends