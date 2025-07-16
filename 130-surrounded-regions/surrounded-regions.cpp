class Solution {
public:
    bool valid(int i,int j,int m,int n){
        if(i<m&&j<n&&i>=0&&j>=0) return true;
        return false;
    }
    void dfs(int i,int j,int m,int n,vector<vector<int>>&visited,vector<vector<char>>&board,vector<vector<int>>&move){
        for(auto &a:move){
            int ii=i+a[0];
            int jj=j+a[1];
            if(valid(ii,jj,m,n)){
                if(visited[ii][jj]==0&&board[ii][jj]=='O'){
                    visited[ii][jj]=1;
                    dfs(ii,jj,m,n,visited,board,move);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>visited(m,vector<int>(n));
        vector<vector<int>>move={
            {-1,0},{0,-1},{1,0},{0,1}
        };
        for(int i=0;i<m;i++){
            if(visited[i][0]==0&&board[i][0]=='O')visited[i][0]=1,dfs(i,0,m,n,visited,board,move);
            if(visited[i][n-1]==0&&board[i][n-1]=='O')visited[i][n-1]=1,dfs(i,n-1,m,n,visited,board,move);
        }
        for(int i=0;i<n;i++){
            if(visited[0][i]==0&&board[0][i]=='O')visited[0][i]=1,dfs(0,i,m,n,visited,board,move);
            if(visited[m-1][i]==0&&board[m-1][i]=='O')visited[m-1][i]=1,dfs(m-1,i,m,n,visited,board,move);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]!=1){
                    board[i][j]='X';
                }
            }
        }
    }
};