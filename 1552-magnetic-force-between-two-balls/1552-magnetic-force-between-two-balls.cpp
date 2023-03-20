class Solution {
public:
    // aggressive cow
    
    bool check(vector<int>& position, int m,int mid){
        int c=1;
        int p=position[0]; //
        for(int i=1;i<position.size();i++){
            if(position[i]-p>=mid){
                c++;
                p=position[i];
            }
        }
        
        if(c<m)return false;
        
        else
            return true;
    }
    int maxDistance(vector<int>& position, int m) {
        
        sort(position.begin(),position.end());
        
        int l=1;
        int h=INT_MIN;
        for(int i=0;i<position.size();i++){
            h=max(h,position[i]);
        }
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(check(position,m,mid)){
                l=mid+1;
                ans=mid;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};