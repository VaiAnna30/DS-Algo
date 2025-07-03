class Solution {
public:
    vector<int>visited;
    void dfs(vector<vector<int>>&list,int start){
        visited[start]=1;
        for(auto &a:list[start]){
            if(visited[a]==0)dfs(list,a);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>list(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }
        visited.resize(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                count++;
                dfs(list,i);
            }
        }
        return count;
    }
};