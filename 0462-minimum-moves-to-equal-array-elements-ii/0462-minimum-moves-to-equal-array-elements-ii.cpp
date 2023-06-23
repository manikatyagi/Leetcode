class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        // convert to median 
        
        int m=0;
        if(n%2==0)m=(nums[n/2]+nums[(n+1)/2])/2;
        else 
            m=nums[n/2];
        
        int moves=0;
        for(int i=0;i<n;i++){
            moves+=abs(nums[i]-m);
        }
        return moves;
    }
};