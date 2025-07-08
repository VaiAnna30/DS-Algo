class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>v=edges;
        for(auto &a:edges){
            v.push_back({a[1],a[0],a[2]});
        }
        vector<vector<int>>graph(n,vector<int>(n,1e9));
        for(auto &a:v){
            graph[a[0]][a[1]]=a[2];
        }
        for(int i=0;i<n;i++){
            graph[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(graph[i][k]!=1e9&&graph[k][j]!=1e9){
                        graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                    }
                }
            }
        }
        int index=-1;
        int vall=n+1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(graph[i][j]<=distanceThreshold)count++;
            }
            if(vall>=count){
                vall=count;
                index=i;
            }
        }
        return index;
    }
};
