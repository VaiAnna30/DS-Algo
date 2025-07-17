class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>list(n);
        for(int i=0;i<n;i++){
            for(auto &a:graph[i]){
                list[a].push_back(i);
            }
        }
        vector<int>indegree(n);
        for(auto &a:list){
            for(auto &aa:a){
                indegree[aa]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto &a:list[node]){
                indegree[a]--;
                if(indegree[a]==0)q.push(a);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};