class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)q.push({{i,j},0});
            }
        }
        vector<vector<int>>moves={
            {-1,0},{1,0},{0,1},{0,-1}
        };
        auto check=[&](int ii,int jj){
            if(ii<m&&ii>=0&&jj>=0&&jj<n)return true;
            return false;
        };
        int ans=0;
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dis=q.front().second;
            
            ans=max(ans,dis);
            q.pop();

            for(auto &a:moves){
                int ii=i+a[0];
                int jj=j+a[1];
                if(check(ii,jj)){
                    if(grid[ii][jj]==1)q.push({{ii,jj},dis+1}),grid[ii][jj]=2;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return ans;
    }
};