class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>ans(n,vector<int>(n,0));
        
        //[[0,0,0],[0,0,0],[0,0,0]]
        
        int i,j;
        int lowRow=0,highRow=n-1;
        int lowCol=0,highCol=n-1;
        int c=1;
        int tot=n*n;
        while(c<=tot){
            
            for(int i=lowCol;i<=highCol;i++){
                ans[lowRow][i]=c;
                c++;
            }
            lowRow++;
            
            for(int i=lowRow;i<=highRow;i++){
                ans[i][highCol]=c;
                c++;
            }
            highCol--;
            
            
             for(int i=highCol;i>=lowCol;i--){
                ans[highRow][i]=c;
                c++;
            }
            highRow--;
            
             for(int i=highRow;i>=lowRow;i--){
                ans[i][lowCol]=c;
                c++;
            }
            lowCol++;
            
            
            
        }
        
        return ans;
        
    }
};