class DSU{
    vector<int>parent,rank;
    public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findultimateparent(int u){
        if(parent[u]==u) return u;
        return parent[u]=findultimateparent(parent[u]);
    }

    void connect(int u,int v){
        int up_u=findultimateparent(u);
        int up_v=findultimateparent(v);
        if(rank[up_u]<rank[up_v]){
            parent[up_u]=up_v;
        }else if(rank[up_v]<rank[up_u]) {
            parent[up_v]=up_u;
        }else{
            parent[up_v]=up_u;
            rank[up_u]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DSU ds(n);
        unordered_map<string,int>m;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m.find(accounts[i][j])==m.end()){
                    m[accounts[i][j]]=i;
                }else{
                    ds.connect(m[accounts[i][j]],i);
                }
            }
        }
        vector<vector<string>>merged(n);
        for(auto it:m){
            string mail=it.first;
            int node=ds.findultimateparent(it.second);
            merged[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(merged[i].size()==0)continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto a:merged[i])temp.push_back(a);
            ans.push_back(temp);
        }
        return ans;
    }
};