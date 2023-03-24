//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>st;
        
        for(int i=0;i<n;i++){
            st.push(i);   // 0 1 2 
        }
        
        while(st.size()>1){
            
            int a=st.top();  // 2  1
            st.pop();
            
            int b=st.top();  //1  0
            st.pop();
            
            // if a knows b
            if(M[a][b]==1){       // 
                st.push(b);     // 0 1   
            }
        
            // if b knows a
           else{   // 0-1
                st.push(a);     // 1
            }
            
        }
        
        for(int i=0;i<n;i++){
            if(i!=st.top() and (M[st.top()][i]==1 or M[i][st.top()]==0))
               return -1;
        }
        
        return st.top();
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends