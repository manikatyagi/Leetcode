class Solution {
public:
    
    bool check(vector<int>& time, int totalTrips,long long mid){
        long long sum=0;
        
        for(int i=0;i<time.size();i++){
            sum+=(mid/time[i]);
            
        }
        return sum>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
      
        long long  l=1;
        long long h=1e14;
        long long ans=-1;
        
        while(l<=h){
            long long mid=l+(h-l)/2;
            
            if(check(time,totalTrips,mid)){
                h=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};