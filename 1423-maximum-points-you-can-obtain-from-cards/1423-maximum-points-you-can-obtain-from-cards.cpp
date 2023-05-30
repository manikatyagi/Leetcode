class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int tot=0;
        int n=cardPoints.size();
        for(int i=0;i<n;i++){
            tot+=cardPoints[i];
        }
         if(k==n)return tot;
        int ans=0;
        int sum=0;
        int j=0;
        for(int i=0;i<n;i++){
            sum+=cardPoints[i];
            if(i>=n-k-1){
                int diff=tot-sum;
                ans=max(ans,diff);
                sum-=cardPoints[j];
                j++;
                
            }
        }
       
        return ans;
    }
};