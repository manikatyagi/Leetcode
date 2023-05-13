//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        unordered_set<string>se(wordList.begin(),wordList.end());
       
        queue<string>q;
        
        q.push(startWord);
        int ans=1;
        
        while(!q.empty()){
            
            int n=q.size();
            
            while(n-->0){
                
                string f=q.front();
                q.pop();
                if(f==targetWord)return ans;
                
                se.erase(f);
                for(int i=0;i<f.size();i++){
                    char c=f[i];
                    
                    for(int j=0;j<26;j++){
                        f[i]='a'+j;
                        
                        if(se.find(f)!=se.end()){
                            q.push(f);
                        }
                    }
                    f[i]=c;
                }
            }
            ans++;
        }
       return 0; 
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends