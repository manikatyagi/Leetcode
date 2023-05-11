//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    
    int maxStop(int n, int m, vector<vector<int>> &trains) {
        // code here
        vector<int>plat(n+1,-1);
        //
        // 1 2 3
        vector<pair<int,int>>t;
        //1030,1000|1030,1010|1005,900    1020,1000|1230,1030           1230,1200
        // 1                              2                                  3
        for(int i=0;i<m;i++){
            t.push_back({trains[i][1],i});
        }
        
        sort(t.begin(),t.end());
        int maxStops=0;
        for(int i=0;i<m;i++){
            int tidx=t[i].second;
            if(plat[trains[tidx][2]]<=trains[tidx][0]){
                plat[trains[tidx][2]]=t[i].first;
                maxStops++;
            }
        }
        return maxStops;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> trains(m, vector<int>(3));
        Matrix::input(trains,m,3);
        
        Solution obj;
        int res = obj.maxStop(n, m, trains);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends