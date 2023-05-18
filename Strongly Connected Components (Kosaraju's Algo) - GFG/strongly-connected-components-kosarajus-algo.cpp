//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void getFinishTime(stack<int>&st,vector<vector<int>>& adj,int curr,vector<int>&vis){
	    
	    vis[curr]=1;
	    
	    for(auto it:adj[curr]){
	        if(!vis[it])
	          getFinishTime(st,adj,it,vis);
	    }
	    
	    st.push(curr);
	}
	
	
   void dfs(int curr,vector<int>&vis,vector<int>Radj[]){
       vis[curr]=1;
       
       for(auto it:Radj[curr]){
           if(vis[it]==0){
               dfs(it,vis,Radj);
           }
       }
   }
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int>vis(V,0);
        stack<int>st;
        // finish time
        for(int i=0;i<V;i++){
            if(vis[i]==0)
                getFinishTime(st,adj,i,vis);
        }
        
        // reverse graph
        vector<int>Radj[V];
        
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                Radj[it].push_back(i);
            }
        }
        
        
        int scc=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            if(vis[node]==0){
                scc++;
                dfs(node,vis,Radj);
            }
            
        }
        
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends