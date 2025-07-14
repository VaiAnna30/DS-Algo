class Solution {
public:
    vector<vector<int>>move={
        {-1,0},{1,0},{0,-1},{0,1}
    };
    bool valid(int i,int j,int n){
        if(i>=0&&j>=0&&i<n&&j<n) return true;
        return false;
    }
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&visited,set<pair<int,int>>&s){
        int n=grid.size();
        s.insert({i,j});
        
        for(auto &a:move){
            int ii=i+a[0];
            int jj=j+a[1];
            if(valid(ii,jj,n)){
                if(visited[ii][jj]==0&&grid[ii][jj]==1){
                    visited[ii][jj]=1;
                    dfs(ii,jj,grid,visited,s);
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<pair<int,int>,int>>q;
        
        vector<set<pair<int,int>>>v;
        vector<vector<int>>visited(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0&&grid[i][j]==1){
                    set<pair<int,int>>s;
                    visited[i][j]=1;
                    dfs(i,j,grid,visited,s);
                    v.push_back(s);
                }
            }
        }
        vector<vector<int>>distance(n,vector<int>(n,1e9));
        for(auto &a:v[0]){
            int i=a.first;
            int j=a.second;
            q.push({{i,j},0});
            distance[i][j]=0;
        }
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int d=q.front().second;
            pair<int,int>p={i,j};
            if(v[1].find(p)!=v[1].end()&&grid[i][j]==1) return d-1;
            q.pop();
            for(auto &a:move){
                int ii=i+a[0];
                int jj=j+a[1];
                if(valid(ii,jj,n)){
                    if(distance[ii][jj]>d+1){
                        distance[ii][jj]=d+1;
                        q.push({{ii,jj},d+1});
                    }
                }
            }
        }
        return -1;


        // for(auto &a:v[0]){
        //     int i=a.first;
        //     int j=a.second;
        //     bool found=false;
        //     for(auto &a:move){
        //         int ii=i+a[0];
        //         int jj=j+a[1];
        //         if(grid[ii][jj]==0) found=true;
        //     }
        //     if(!found)v[0].erase(a);
        // }
        // for(auto &a:v[1]){
        //     int i=a.first;
        //     int j=a.second;
        //     bool found=false;
        //     for(auto &a:move){
        //         int ii=i+a[0];
        //         int jj=j+a[1];
        //         if(valid(ii,jj,n)&&grid[ii][jj]==0) found=true;
        //     }
        //     if(!found)v[1].erase(a);
        // }

        // queue<pair<pair<int,int>,int>>q;
        // for(auto &a:v[0])q.push({a,0});



    }
};