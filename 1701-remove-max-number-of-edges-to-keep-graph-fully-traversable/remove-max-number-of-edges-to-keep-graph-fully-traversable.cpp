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
        if(n==parent[n])return n;
        return parent[n]=findultimateparent(parent[n]);
    }

    bool unionbyrank(int u,int v){
        int up_u=findultimateparent(u);
        int up_v=findultimateparent(v);
        if(up_u==up_v)return false;
        if(rank[up_u]<rank[up_v]){
            parent[up_u]=up_v;
        }else if(rank[up_u]>rank[up_v]){
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet ds1(n);
        DisjointSet ds2(n);
        int remove=0;
        int count1=0,count2=0;
        for(auto &a:edges){
            if(a[0]==3){
                bool by1=ds1.unionbyrank(a[1],a[2]);
                bool by2=ds2.unionbyrank(a[1],a[2]);
                if(!by1&&!by2) remove++;
                else{
                    if(by1)count1++;
                    if(by2)count2++;
                }
            } 
        }

        for(auto &a:edges){
            if(a[0]==1){
                bool by1=ds1.unionbyrank(a[1],a[2]);
                if(!by1)remove++;
                else count1++;
            }
        }

        for(auto &a:edges){
            if(a[0]==2){
                bool by2=ds2.unionbyrank(a[1],a[2]);
                if(!by2)remove++;
                else count2++;
            }
        }
        if(count1<n-1||count2<n-1)return -1;
        return remove;
    }
};