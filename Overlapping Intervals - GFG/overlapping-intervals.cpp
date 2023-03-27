//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         sort(intervals.begin(),intervals.end());
         // [[1,3] [2,4] [6,8] [9,10]]
         
         // [[1,9] [2,4] [4,7] [6,8]]
         //   
         vector<vector<int>>ans;
         ans.push_back(intervals[0]);  // 1 3
         int j=0;
         for(int i=1;i<intervals.size();i++){
             if(ans[j][1] >=intervals[i][0]){
                 ans[j][1]=max(ans[j][1], intervals[i][1]); // 1,4
             }
             else{
                 ans.push_back(intervals[i]);
                 j++;
             }
             
         }
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends