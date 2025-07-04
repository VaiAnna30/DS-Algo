class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1) return -1;
        vector<vector<int>>moves={
            {-1,-1},{-1,0},{-1,1},
            {0,-1},{0,1},
            {1,-1},{1,0},{1,1}
        };
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        auto valid=[&](int i,int j){
            if(i<n&&j<n&&i>=0&&j>=0) return true;
            return false;
        };
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int d=q.front().second;
            if(i==n-1&&j==n-1) return d;
            q.pop();
            for(auto &a:moves){
                int ii=i+a[0];
                int jj=j+a[1];
                if(valid(ii,jj)){
                    if(grid[ii][jj]==0){
                        grid[ii][jj]=1;
                        q.push({{ii,jj},d+1});
                    }
                }
            }
        }
        return -1;
    }
};