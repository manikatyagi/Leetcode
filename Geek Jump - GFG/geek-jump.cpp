//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
 
 int func(vector<int>& height,int idx,vector<int>&dp){
     
     if(idx==0)return 0;
     
     if(dp[idx]!=-1)return dp[idx];
     
     int left=func(height,idx-1,dp)+abs(height[idx]-height[idx-1]);
     int right=INT_MAX;
     
     if(idx>1)
        right=func(height,idx-2,dp)+abs(height[idx]-height[idx-2]);
        
    return dp[idx]=min(left,right);
     
 }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n+1,-1);
        
       return  func(height,n-1,dp);
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends