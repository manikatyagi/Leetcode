class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>se(wordList.begin(),wordList.end());
       
        queue<string>q;
        
        q.push(beginWord);
        int ans=1;
        
        while(!q.empty()){
            
            int n=q.size();
            
            while(n-->0){
                
                string f=q.front();
                q.pop();
                if(f==endWord)return ans;
                
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