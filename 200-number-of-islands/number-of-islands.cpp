class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n));
        vector<vector<int>>move={
            {-1,0},{0,-1},{0,1},{1,0}
        };
        function<void(int,int)> dfs=[&](int i,int j){
            for(auto &a:move){
                int ii=i+a[0];
                int jj=j+a[1];
                if(ii>=0&&jj>=0&&ii<m&&jj<n){
                    if(visited[ii][jj]==0&&grid[ii][jj]=='1'){
                        visited[ii][jj]=1;
                        dfs(ii,jj);
                    } 
                }
            }
            return;
        };
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0&&grid[i][j]=='1'){
                    visited[i][j]=1;
                    count++;
                    dfs(i,j);
                }
            }
        }
        return count;
    }
};