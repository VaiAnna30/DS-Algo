class Solution {
public:
    int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>list(n);
        for(auto &a:roads){
            list[a[0]].push_back({a[1],a[2]});
            list[a[1]].push_back({a[0],a[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        vector<long long>ans(n,LLONG_MAX);
        vector<int>ways(n,0);
        ways[0]=1;
        q.push({0,0});
        ans[0]=0;
        while(!q.empty()){
            long long time=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto &a:list[node]){
                int nod=a.first;
                long long tim=a.second;

                if(ans[nod]>time+tim){
                    ans[nod]=time+tim;
                    q.push({ans[nod],nod});
                    ways[nod]=ways[node];
                }
                else if(ans[nod]==time+tim){
                    ways[nod]=(ways[nod]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
        
    }
};