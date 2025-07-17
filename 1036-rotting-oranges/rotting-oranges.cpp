class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>move={
            {-1,0},{1,0},{0,-1},{0,1}
        };
        auto valid=[&](int i,int j){
            if(i>=0&&j>=0&&i<m&&j<n)return true;
            return false;
        };
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(auto &a:move){
                int ii=i+a[0];
                int jj=j+a[1];
                if(valid(ii,jj)&&grid[ii][jj]==1){
                    grid[ii][jj]=2;
                    ans[ii][jj]=1+ans[i][j];
                    q.push({ii,jj});
                }
            }
        }
        int  maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
                maxi=max(maxi,ans[i][j]);
            }
        }
        return maxi;
    }
};