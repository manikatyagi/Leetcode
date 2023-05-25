class Solution {
public:
    bool possible(int r,int c,char no,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[i][c]==no)return false;
            
            if(board[r][i]==no)return false;
            
            
            if(board[3*(r/3)+ i/3][3* (c/3)+ i%3]==no)return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                
                if(board[r][c]=='.'){
                    
                    for(char no='1';no<='9';no++){
                        
                        if(possible(r,c,no,board)){
                            board[r][c]=no;
                            
                            if(solve(board))return true;
                            
                            else
                                board[r][c]='.';
                            
                        }
                    
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
       solve(board);
        
    }
};