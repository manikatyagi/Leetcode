class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
          int n=grid.size();
        unordered_map<int,vector<int>>mp;
        
        for(int i=0;i<n;i++){
            
            mp[i]=grid[i];
        }
        
        unordered_map<int,vector<int>>mp2;
        
        for(int i=0;i<n;i++){
            
            vector<int>v;
            for(int j=0;j<n;j++){
                
                v.push_back(grid[j][i]);
            }
            mp2[i]=v;
            
        }
        
        // 0 - 3 1 2 2   1-1 4 4 5    2-2 4 2 2   3-2 4 2 2 
        // 0- 3 1 2 2    1-1 4 4 4    2-2 4 2 2  3-2 5 2 2
        
        int c=0;
        for(auto it:mp){
            
            for(auto it2:mp2){
                
                if(it.second==it2.second)
                    c++;
            }
        }
        return c;
    }
};