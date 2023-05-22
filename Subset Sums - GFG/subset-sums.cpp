//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void func(int &sum,vector<int> arr,int n,vector<int>&v,int idx){
        if(idx==n){
            v.push_back(sum);
            return ;
        }
        
        sum+=arr[idx];
        func(sum,arr,n,v,idx+1);
        sum-=arr[idx];
        func(sum,arr,n,v,idx+1);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int>v;
        
        int sum=0;
        func(sum,arr,n,v,0);
        
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends