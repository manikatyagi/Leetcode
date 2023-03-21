class Solution {
public:
    bool check(vector<int>& nums, int k , int m){
        // 1 1 6
        // i   j
        // 0 1 2
        int c=0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            
            while(j<nums.size() and nums[j]-nums[i]<=m){ // 2
                j++;
            }
            c+=j-i-1;  //  
        }
        return c>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int low=0;
        
        sort(nums.begin(),nums.end());
        
        int high=nums[nums.size()-1]-nums[0]; // 6-1=5
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(check(nums,k,mid)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};