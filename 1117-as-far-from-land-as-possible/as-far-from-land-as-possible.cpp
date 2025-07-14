class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>ans(n,vector<int>(n));
        queue<pair<int,pair<int,int>>>q;
        int count0=0,count1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count1++;
                    q.push({0,{i,j}});
                }else{
                    count0++;
                    ans[i][j]=1e9;
                }
            }
        }
        if(count0==0) return -1;
        if(count1==0) return -1;
        vector<vector<int>>move={
            {-1,0},{1,0},{0,-1},{0,1}
        };
        auto valid=[&](int i,int j){
            if(i>=0&&j>=0&&i<n&&j<n) return true;
            return false;
        };
        while(!q.empty()){
            int d=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            for(auto &a:move){
                int ii=i+a[0];
                int jj=j+a[1];
                if(valid(ii,jj)){
                    if(grid[ii][jj]==0){
                        if(d+1<ans[ii][jj]){
                            ans[ii][jj]=d+1;
                            q.push({d+1,{ii,jj}});
                        }
                    }
                }
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j]==1e9) return -1;
                maxi=max(maxi,ans[i][j]);
            }
        }
        return maxi;
    }
};