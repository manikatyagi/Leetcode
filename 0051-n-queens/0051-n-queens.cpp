class Solution {
public:
    bool issafe(int n,int r,int c,vector<string>&v){
        // check in row
        
        int row=r,col=c;
        while(col>=0){
            if(v[row][col]=='Q')return false;
            col--;
        }
        
       
        // diagonal upper left side 
         row=r,col=c;
        while(row>=0 and col>=0){
            if(v[row][col]=='Q')return false;
            row--,col--;
            
        }
        // diagonal lower left;
        row=r,col=c;
        
        while(row<n and col>=0){
            if(v[row][col]=='Q')return false;
            row++;
            col--;
        }
        return true;
    }
    void func(int col,int n,vector<string>&v,vector<vector<string>>&ans){
        if(col==n){
            ans.push_back(v);
            return;
        } 
        for(int r=0;r<n;r++){   // fixed row traversing in column   
            if(issafe(n,r,col,v)){
                v[r][col]='Q';
                func(col+1,n,v,ans);
                v[r][col]='.';
            }
        }      
            
    }
	vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
		vector<string>v;
        string s(n,'.');
        
        for(int i=0;i<n;i++){
            v.push_back(s);
        }
        func(0,n,v,ans);
        return ans;
        
	}
};