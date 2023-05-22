class Solution {
public:
    void func(int idx,vector<int>& nums,vector<vector<int>>&ans, vector<int>&v){
   
            ans.push_back(v);

        
        for(int i=idx;i<nums.size();i++){
            if(i>idx and nums[i]==nums[i-1])continue ;
            
            v.push_back(nums[i]);
            func(i+1,nums,ans,v);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>v;
        
        func(0,nums,ans,v);
        
        return ans;
    }
};