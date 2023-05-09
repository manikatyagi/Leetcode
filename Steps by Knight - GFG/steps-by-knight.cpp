//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&k,vector<int>&target,int n)
	{
	    // Code here
	    queue<pair<int,int>>q;
	    q.push({k[0]-1,k[1]-1});
	    // all direction
	    int dir[8][2]={{1,2},{2,1},{1,-2},{2,-1},{-1,2},{-2,1},{-1,-2},{-2,-1}};
	     // {4,5}
	     int ans=0;
	     vector<vector<int>>vis(n,vector<int>(n,0));
	     vis[k[0]-1][k[1]-1]=1;
	     
	    while(!q.empty()){
	        int s=q.size();
	      //  cout<<s<<endl;
	        while(s-->0){
	            int x=q.front().first;
	            int y=q.front().second;
	            
	            q.pop();
	            
	            if(x==target[0]-1 and y==target[1]-1)return ans;
	            vis[x][y]=1;
	            for(auto d:dir){
	                int r=x+d[0];
	                int c=y+d[1];
	                
	                if(r>=0 and c>=0 and r<n and c<n and vis[r][c]!=1){
	                    q.push({r,c});
	                    vis[r][c]=1;
	                }
	            }
	        }
	        ans++;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends