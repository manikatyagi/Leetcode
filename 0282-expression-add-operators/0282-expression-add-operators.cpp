class Solution {
public:
    vector<string>ans;
    
    void dfs(int idx,  const string& s,long resSoFar, long prevNum,string& numstr,int& target){
        if(idx==numstr.size()){
            if(resSoFar==target)ans.push_back(s);
            return ;
        }
        
        string sub;
        long currNum=0;
        for(int i=idx;i<numstr.size();i++){
            if(i>idx && numstr[idx]=='0')break;
            sub+=numstr[i];
            currNum = currNum*10+(numstr[i]-'0');
            if(idx==0){
                dfs(i+1,s+sub,currNum,currNum,numstr,target);
            }
            else{
                 dfs(i+1,s+"+"+sub,resSoFar+currNum,currNum,numstr,target);
                 dfs(i+1,s+"-"+sub,resSoFar-currNum,-currNum,numstr,target);
                 dfs(i+1,s+"*"+sub,resSoFar-prevNum+prevNum*currNum,currNum*prevNum,numstr,target);
            }
            
        }
    }
    vector<string> addOperators(string numstr, int target) {
        string s="";
        
        dfs(0,s,0,0,numstr,target);
        return ans;
    }
};