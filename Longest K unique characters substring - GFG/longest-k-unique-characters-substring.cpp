//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
       unordered_map<char,int>mp;
       int ans=-1;
       int j=0,i;
       for(i=0;i<s.size();i++){
           
           mp[s[i]]++;
           
           while(mp.size()>k){
               mp[s[j]]--;
               
               if(mp[s[j]]==0)mp.erase(s[j]);
               
               j++;
               
           }
           ans=max(ans,i-j+1);
       }
       if(i==s.size() and mp.size()<k)return -1;
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends