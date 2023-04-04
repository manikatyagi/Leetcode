class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        
        vector<int>v;
    
        int low=0;
        int high=nums.size()-k;
        
        while(low<high){
            int mid=low+(high-low)/2;
            
            if(x-nums[mid]<=nums[mid+k]-x){
                high=mid;
            }
            else
                low=mid+1;
        }
        
        for(int i=0;i<k;i++){
            v.push_back(nums[i+low]);
        }
        return v;
    }
};