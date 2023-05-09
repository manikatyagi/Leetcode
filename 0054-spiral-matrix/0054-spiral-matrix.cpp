class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       vector<int>ans;
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        int lowRow=0,highRow=m-1; // 3
        int lowCol=0,highCol=n-1;//3
        
        int i,j;
        while(lowRow<=highRow and lowCol<=highCol){
            
            i=lowRow,j=lowCol;
            
            while(j<=highCol){
              ans.push_back(matrix[i][j]);
              j++;
            }
        
            lowRow++;// 1
             
            
            i=lowRow,j=highCol;
    
            while(i<=highRow){
               ans.push_back(matrix[i][j]);
               i++;
           }
           
           highCol--; // 2
           if(lowRow>highRow or lowCol>highCol)break;
            
           
           i=highRow,j=highCol;
        
           while(j>=lowCol){
             ans.push_back(matrix[i][j]);
             j--;
           }
        
           highRow--; // 2
            
           i=highRow,j=lowCol;
        
           while(i>=lowRow){
             ans.push_back(matrix[i][j]);
             i--;
           }
           lowCol++; // 1
        }
      
        return ans;
    }
};