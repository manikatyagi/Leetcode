class Solution {
public:
    int bs(vector<int>& potions, int& k,long long& s){
        int high=potions.size()-1;
        int low=0;
        
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long t=(long long) potions[mid]* (long long) k;
            if(t>=s){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return potions.size()-low;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(),potions.end());
        
        // [1 2 3 4 5]
        vector<int>ans(spells.size());
        for(int i=0;i<spells.size();i++){
            
            ans[i]=bs(potions,spells[i],success);
        }
        return ans;
    }
};