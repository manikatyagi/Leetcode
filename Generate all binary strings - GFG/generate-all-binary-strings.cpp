//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void func(string str,int num,int idx){
        
        if(idx==num){
            cout<<str<<" ";
            return ;
        }
        func(str+'0',num,idx+1);
        if(str[idx-1]!='1')
          func(str+'1',num,idx+1);
    }
    void generateBinaryStrings(int num){
        //Write your code
        string str="";
        func(str,num,0);
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends