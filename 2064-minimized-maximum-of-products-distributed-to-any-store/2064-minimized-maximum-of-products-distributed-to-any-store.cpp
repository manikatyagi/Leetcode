class Solution {
public:
    bool check(vector<int>& quantities,int mid, int n){
        int c=0;
        for(int i=0;i<quantities.size();i++){
            int d=quantities[i]/mid;
            
            if(quantities[i]%mid!=0)
                d++;
            
            c+=d;
        }
        
       return c<=n;
            
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int l=1;
        int h=INT_MIN;
        
        for(int i=0;i<quantities.size();i++){
            h=max(h,quantities[i]);  // 11
        }
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(check(quantities,mid,n)){
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