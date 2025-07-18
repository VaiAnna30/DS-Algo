class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool ans=solve(board);
    }
    bool solve(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(is_valid(board,i,j,c)){
                            board[i][j]=c;
                            if(solve(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool is_valid(vector<vector<char>>&board,int row,int col,char num){
        for(int i=0;i<9;i++){
            if(board[i][col]==num) return false;
            if(board[row][i]==num) return false;
            if(board[((3*(row/3))+(i/3))][((3*(col/3))+(i%3))]==num) return false;
        }
        return true;
    }
};