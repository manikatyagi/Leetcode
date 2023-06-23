class Solution {
public:
    long long func(int m, vector<pair<long,long>>v){
        
       long long cost=0;
        
        for(int i=0;i<v.size();i++){
            cost+=abs(v[i].first-m)*v[i].second;
        }
        return cost;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        vector<pair<long,long>>v;
        long long n=nums.size();
        
        for(int i=0;i<n;i++){
            v.push_back({nums[i],cost[i]});
        }
        
        sort(v.begin(),v.end());   // 1-2   2-14   3-3  5-1
        
        // 1 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 3 3 3 5
        
        
       long long median=0;
        long long total=0;
        
        for(int i=0;i<n;i++)
            total+=v[i].second;   // 20
        
        long long sum=0;
        int i=0;
        while(sum<(total+1)/2  and i<n){  
            sum+=v[i].second;  //2 16
            median=v[i].first;
            i++;
        }
        
        return func(median,v);
    }
};