class Solution {
public:
    vector<int>visited;
    vector<int>check;
    bool dfs(vector<vector<int>>&graph,int node,int parent){
        if(parent!=-1) check[node]=(1^check[parent]);
        else check[node]=0;
        bool ans=true;
        for(auto &a:graph[node]){
            if(a!=parent){
                if(check[a]==check[node]) return false;
                if(visited[a]==0){
                    visited[a]=1;
                    ans=ans&&dfs(graph,a,node);
                }
            }
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        visited.resize(n,0);
        check.resize(n,-1);
        bool ans=true;
        for(int i=0;i<n;i++){
            if(visited[i]==0)visited[i]=1,ans=ans&&dfs(graph,i,-1);
        }
        return ans;
    }
};