class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double ans=INT_MIN;
        double sum=0;
        int j=0;
        // 1,12,-5,-6,50,3
        // j          i
         for(int i=0;i<nums.size();i++){
          
             sum+=nums[i];
             if(i>=k-1){
                 double avg=sum/k;
                 
                 ans=max(ans,avg);
                 sum-=nums[j];
                 j++;
             }
           
         }
        return ans;
    }
};