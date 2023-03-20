class Solution {
public:
    bool check(vector<int>& dist, double hour, int m){
        double sum=0;
        
        for(int i=0;i<dist.size()-1;i++){
            
             sum+=ceil(dist[i]/(m*1.00));
          
        }
        sum+=(dist[dist.size()-1]/(m*1.00));
        
       if(sum>hour)return false;
        else
            return true;
        
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1;
        int h=1e7;
        int ans=-1;
        while(l<=h){
            int m=l+(h-l)/2;
            
            if(check(dist,hour,m)){
                h=m-1;
                ans=m;
            }
            else{
                l=m+1;
            }
        }
        
        return ans;
    }
};