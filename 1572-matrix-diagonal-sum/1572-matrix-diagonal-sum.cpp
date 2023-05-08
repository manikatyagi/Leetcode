class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int n=mat.size();
       
        for(int i=0,j=0;i<n;i++,j++){
            sum+=mat[i][j];
            sum+=mat[i][n-1-j];
        }
        
        if(n%2!=0)sum-=mat[n/2][n/2];
        
        return sum;
    }
};