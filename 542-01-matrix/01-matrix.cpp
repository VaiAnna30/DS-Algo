class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)q.push({{i,j},0}),ans[i][j]=0;
            }
        }

        vector<vector<int>>move={
            {1,0},{-1,0},{0,1},{0,-1}
        };

        auto valid=[&](int i,int j){
            if(i<m&&i>=0&&j<n&&j>=0) return true;
            return false;
        };

        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dist=q.front().second;

            q.pop();

            for(auto &a:move){
                int ii=i+a[0];
                int jj=j+a[1];
                if(valid(ii,jj)){
                    if(ans[ii][jj]==-1){
                        ans[ii][jj]=dist+1;
                        q.push({{ii,jj},dist+1});
                    }
                }
            }
        }
        return ans;
    }
};