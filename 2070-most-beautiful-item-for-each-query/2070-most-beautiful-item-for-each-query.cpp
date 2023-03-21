class Solution {
public:
    int bs(vector<vector<int>>& items, int t,vector<int>&maxBeauty){
        int l=0;
        int h=items.size()-1;
        int ans=0;
        while(l<=h){
            int m=l+(h-l)/2;
            
            if(items[m][0]<=t){
                l=m+1;
                ans=maxBeauty[m];
            }
            else
                h=m-1;
            
        }
        
        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
       int n = items.size();
        vector<int>v;
        
        sort(items.begin(),items.end());
        
        vector<int>maxBeauty(n);
        
        maxBeauty[0]=items[0][1];
        for(int i=1;i<items.size();i++){                // 1 2 3 3 5
            maxBeauty[i]=max(maxBeauty[i-1],items[i][1]); // 2 4 4 5 6
        }
        
        for(int i=0;i<queries.size();i++){
    
            v.push_back(bs(items,queries[i],maxBeauty));
        }
       return v; 
    }
};