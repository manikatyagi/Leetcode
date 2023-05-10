//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int curr,vector<int>&vis,vector<vector<int>>&adj, vector<int>&ord){
        vis[curr]=1;
        ord[curr]=1;
        for(auto it:adj[curr]){
            if(vis[it]==0){
                bool c=dfs(it,vis,adj,ord);
                if(c==true)return true;
            }
            
            else if(ord[it]==1){
                return true;
            }
        }
        ord[curr]=0;
        
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>>adj(N);
	    
	    for(auto it:prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    // [[] [0] [1] [2]]
	    vector<int>vis(N,0);
	    vector<int>ord(N,0);
	    for(int i=0;i<N;i++){
	        if(vis[i]==0){
	            if(dfs(i,vis,adj,ord)==true)return false;
	        }
	    }
	    
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends