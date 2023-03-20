class Solution {
public:
    
    bool check(int mid , vector<int>& weights, int days){
        int sum=weights[0]; // 1
        int d=1;
        for(int i=1;i<weights.size();i++){
            if(weights[i]+sum<=mid){
                sum+=weights[i];
            }
            else{
                sum=weights[i];
                d++;
            }
        
        }
        
      if(d>days)return false;
      return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low=INT_MIN;
        int high=0;
        for(int i=0;i<weights.size();i++){
            low=max(low,weights[i]);
            high+=weights[i];
        }
       int  ans=-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(check(mid,weights,days)){
                ans=mid;
                high=mid-1;  
            }
            
            else{
                low=mid+1;
            }
        }
     return ans;
        
    }
};