class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
         int s=queries.size();
         vector<int>ans;
        
        vector<int>col(n,0);
        int v=0;
        for(int i=0;i<s;i++){
              
            int idx=queries[i][0];
            int c=queries[i][1];
            
            if(idx-1>=0 and col[idx-1]==c)v++;
            
            if(idx+1<n and col[idx+1]==c)v++;
            
            
            if(idx-1>=0 and col[idx]==col[idx-1] and col[idx]!=0)v--;
            
            if(idx+1<n and col[idx]==col[idx+1] and col[idx]!=0)v--;
            
            
            col[idx]=c;
            
            ans.push_back(v);  
            
        }
        
        return ans;
    }
};