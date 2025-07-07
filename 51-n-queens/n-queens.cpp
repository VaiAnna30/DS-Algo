class Solution {
public:

    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n,vector<int>&checkrow,unordered_set<int>&major_diag,unordered_set<int>&minor_diag){
        if(col==n){
            ans.push_back(board);
            return;
        }
        auto valid=[&](int row,int col){
            if(checkrow[row]==1) return false;
            if(major_diag.find(row-col)!=major_diag.end()) return false;
            if(minor_diag.find(row+col)!=minor_diag.end()) return false;
            return true;
        };
        for(int row=0;row<n;row++){
            if(valid(row,col)){
                board[row][col]='Q';
                checkrow[row]=1;
                major_diag.insert(row-col);
                minor_diag.insert(row+col);
                solve(col+1,board,ans,n,checkrow,major_diag,minor_diag);
                checkrow[row]=0;
                major_diag.erase(row-col);
                minor_diag.erase(row+col);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string str="";
        for(int i=0;i<n;i++){
            str+='.';
        }
        vector<string>board(n,str);
        vector<int>checkrow(n);
        unordered_set<int>major_diag,minor_diag;
        solve(0,board,ans,n,checkrow,major_diag,minor_diag);
        return ans;
    }
};