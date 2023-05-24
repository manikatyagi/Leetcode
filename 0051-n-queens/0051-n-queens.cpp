class Solution {
public:
    bool issafe(int r,int c,int n,vector<string>&board){
        int row=r,col=c;
        
        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }
        
        row=r,col=c;
        
        while(row>=0 and col>=0){
            if(board[row][col]=='Q')return false;
            
            row--;
            col--;
        }
        
        row=r,col=c;
        
        while(row<n and col>=0){
            if(board[row][col]=='Q')return false;
            row++;
            col--;
        }
        return true;
    }
    void func(int col,int n,vector<string>&board,vector<vector<string>>&ans){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        
        for(int row=0;row<n;row++){
            if(issafe(row,col,n,board)){
                board[row][col]='Q';
                func(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }
	vector<vector<string>> solveNQueens(int n) {
        vector<string>board;
        vector<vector<string>>ans;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        func(0,n,board,ans);
        return ans;
	}
};