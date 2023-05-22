class Solution {
public:
     void func(int idx,vector<int>&nums,vector<int>&v,vector<vector<int>>&ans){
         if(idx==nums.size()){
             ans.push_back(v);
             return ;
         }
         
         v.push_back(nums[idx]);
         func(idx+1,nums,v,ans);
         
         v.pop_back();
         
         func(idx+1,nums,v,ans);
     }
    
   

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        vector<vector<int>>ans;
        func(0,nums,v,ans);
       return ans;
    }
};