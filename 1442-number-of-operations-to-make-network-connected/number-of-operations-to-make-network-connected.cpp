
class DisjointSet{
    vector<int>rank,parent;
public:
    DisjointSet(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findultimateparent(int n){
        if(n==parent[n]) return n;
        return parent[n]=findultimateparent(parent[n]);
    }
    
    bool unionbyRank(int u,int v){
        int up_u=findultimateparent(u);
        int up_v=findultimateparent(v);
        if(up_u==up_v) return false;
        if(rank[up_u]<rank[up_v]){
            parent[up_u]=up_v;
        }else if(rank[up_v]<rank[up_u]){
            parent[up_v]=up_u;
        }else{
            parent[up_v]=up_u;
            rank[up_u]++;
        }
        return true;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        DisjointSet ds(n);
        int extraedges=0;
        for(auto &edges:connections){
            if(!ds.unionbyRank(edges[0],edges[1]))extraedges++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(ds.findultimateparent(i)==i)count++;
        }
        count--;
        if(count>extraedges) return -1;
        return count;
    }
};