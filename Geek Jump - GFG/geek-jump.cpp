//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
 
 
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int prev=0;
        int prev2=0;
        
        for(int i=1;i<n;i++){
            int l=prev+abs(height[i-1]-height[i]);
            
            int r=INT_MAX;
            
            if(i>1)
                   r=prev2+abs(height[i-2]-height[i]);
            
            int curr=min(l,r);
            
            prev2=prev;
            prev=curr;
        }
       return prev;
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