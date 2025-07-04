class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>moves={
            {0,-1},{-1,0},{0,1},{1,0}
        };
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        vector<vector<int>>ans(m,vector<int>(n,1e9));
        q.push({0,{0,0}});
        auto valid=[&](int i,int j){
            if(i>=0&&j>=0&&i<m&&j<n) return true;
            return false;
        };
        while(!q.empty()){
            int dist=q.top().first;
            int i=q.top().second.first;
            int j=q.top().second.second;
            q.pop();
            for(auto &a:moves){
                int ii=i+a[0];
                int jj=j+a[1];
                if(valid(ii,jj)){
                    if(ans[ii][jj]>max(dist,abs(heights[i][j]-heights[ii][jj]))){
                        ans[ii][jj]=max(dist,abs(heights[i][j]-heights[ii][jj]));
                        q.push({ans[ii][jj],{ii,jj}});
                    }
                }
            }
        }
        return ans[m-1][n-1]==1e9?0:ans[m-1][n-1];
    }
};