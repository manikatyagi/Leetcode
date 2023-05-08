//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int>&vis,vector<int> adj[], vector<int>&order,int curr){
        vis[curr]=1;
        order[curr]=1;
        
        
        for(int x:adj[curr]){
            if(vis[x]==0){
                bool c=dfs(vis,adj,order,x);
                if(c==true)return true;
            }
            
            else if(order[x]==1)return true;
        }
        
        order[curr]=0;
        
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here 
       vector<int>vis(V,0);
       vector<int>order(V,0);
       for(int i=0;i<V;i++){
           if(vis[i]==0){
              
             bool c=dfs(vis,adj,order,i);
             if(c==true)return true;
           }
       }
       return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends