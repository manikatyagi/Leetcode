class Solution {
public:
    int maxSatisfaction(vector<int>&sat) {
        sort(sat.begin(),sat.end()); // -9 -8 -1 0 5 
        
        int sum=0;
        int i;

        for(i=sat.size()-1 ;i>=0;i--){
            sum+=sat[i];
            
            if(sum<0)break;
            
        }
       i++;
        int ans=0;
       int c=1;
        for(int j=i;j<sat.size();j++){
            ans+=sat[j]*c;
            c++;
        }
        
        return ans;
    }
};