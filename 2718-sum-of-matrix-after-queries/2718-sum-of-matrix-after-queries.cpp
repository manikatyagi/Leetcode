class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& q) {
        
        unordered_set<int>row;
        unordered_set<int>col;
      
        long long ans=0;
        int row_no=n;
        int col_no=n;
        for(int i=q.size()-1;i>=0;i--){
            int type=q[i][0];
            int idx=q[i][1];
            int val=q[i][2];
            
            if(type==0){
                
                if(row.find(idx)!=row.end())
                    continue;
                
                else{
                    ans+=row_no*q[i][2];
                    row.insert(idx);
                    col_no--;
                }
            }
            else{
                if(col.find(idx)!=col.end())
                    continue;
                
                else{
                    ans+=col_no*q[i][2];
                    col.insert(idx);
                    row_no--;
                }
            }
        }
        return ans;
    }
};