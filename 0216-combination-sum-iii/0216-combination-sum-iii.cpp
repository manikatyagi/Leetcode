class Solution {
public:
    
    void func(int k,int t,vector<int>&arr, vector<vector<int>>&ans,vector<int>&v,int idx) {
         
        if(t==0){
            if(v.size()==k)
                ans.push_back(v);
            return ;
        }
        
        for(int i=idx;i<=arr.size();i++){
            
           // if(i>idx and arr[i]==arr[i-1])continue;
            
            if(arr[i]>t)break;
            
            v.push_back(arr[i]);
            func(k,t-arr[i],arr,ans,v,i+1);
            v.pop_back();
        }
     } 
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr;
        
        for(int i=0;i<9;i++){
            arr.push_back(i+1);
        }
        
        vector<vector<int>>ans;
        vector<int>v;
        func(k,n,arr,ans,v,0);
        
        return ans;    
    }
};