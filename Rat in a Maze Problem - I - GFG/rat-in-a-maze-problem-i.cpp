//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void dfs(int x,int y,int n,vector<vector<int>>&vis,vector<string>&v,vector<vector<int>> &m,string s){
        if(x<0 or y<0 or x>=n or y>=n or vis[x][y]==1 or m[x][y]==0)return ;
        
        if(x==n-1 and y==n-1 ){
            v.push_back(s);
            return ;
            
        }
        vis[x][y]=1;
        
        dfs(x+1,y,n,vis,v,m,s+'D');
        dfs(x,y+1,n,vis,v,m,s+'R');
        dfs(x-1,y,n,vis,v,m,s+'U');
        dfs(x,y-1,n,vis,v,m,s+'L');
        
        vis[x][y]=0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>>vis(n,vector<int>(n,0));
        
        if(m[n-1][n-1]==0 or m[0][0]==0)return {"-1"};
        vector<string>v;
        string s="";
        dfs(0,0,n,vis,v,m,s);
    
        return v;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends