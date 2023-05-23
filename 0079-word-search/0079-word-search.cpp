class Solution {
public:
    bool search(int x,int y,string word,vector<vector<char>>& board,int n){
        
        if(n==word.size())return true;
        
        if(x<0 or y<0 or x>=board.size() or y>=board[0].size() or board[x][y]!=word[n])return false;
        
        board[x][y]='!';
        bool temp=search(x+1,y,word,board,n+1)
        or search(x,y+1,word,board,n+1)
       or search(x-1,y,word,board,n+1)
       or search(x,y-1,word,board,n+1);
        
        board[x][y]=word[n];
     return temp;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        
    
        
        for(int i=0;i<board.size();i++){
            
            for(int j=0;j<board[i].size();j++){
                
                if(board[i][j]==word[0] and search(i,j,word,board,0))
                    return true;
            }
        }
        return false;
    }
};