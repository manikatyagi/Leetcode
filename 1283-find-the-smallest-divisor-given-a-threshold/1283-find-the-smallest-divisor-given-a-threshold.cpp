class Solution {
public:
    bool check(vector<int>& nums,int mid, int threshold){
       int sum=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mid!=0){
                sum+=(nums[i]/mid)+1;
            }
            else{
                sum+=(nums[i]/mid);
            }
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int h=-1;
        for(int i=0;i<nums.size();i++){
            h=max(h,nums[i]);
        }
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(nums,mid,threshold)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};