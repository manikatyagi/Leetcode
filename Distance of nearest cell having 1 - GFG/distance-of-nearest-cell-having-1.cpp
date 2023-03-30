//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int r=grid.size();
	    int c=grid[0].size();
	    queue<pair<int,int>>q;
	    
	    vector<vector<int>>arr(r,vector<int>(c,INT_MAX));
	    
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            if(grid[i][j]==1){
	                q.push({i,j});
	                arr[i][j]=0;
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        int i=q.front().first;
	        int j=q.front().second;
	        q.pop();
	        if(i-1>=0 and arr[i][j]+1<arr[i-1][j]){
	            arr[i-1][j]=arr[i][j]+1;
	            q.push({i-1,j});
	        }
	        if(i+1<r and arr[i][j]+1<arr[i+1][j]){
	            arr[i+1][j]=arr[i][j]+1;
	            q.push({i+1,j});
	        }
	        
	        if(j-1>=0 and arr[i][j]+1<arr[i][j-1]){
	            arr[i][j-1]=arr[i][j]+1;
	            q.push({i,j-1});
	        }
	        
	        if(j+1<c and arr[i][j]+1<arr[i][j+1]){
	            arr[i][j+1]=arr[i][j]+1;
	            q.push({i,j+1});
	        }
	        
	        
	    }
	    return arr;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends