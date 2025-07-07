class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>list(n+1);
        for(auto &a:times){
            list[a[0]].push_back({a[1],a[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int>ans(n,1e9);
        q.push({0,k});
        ans[k-1]=0;
        while(!q.empty()){
            int time=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto &a:list[node]){
                int nod=a.first;
                int tim=a.second;

                if(ans[nod-1]>time+tim){
                    ans[nod-1]=time+tim;
                    q.push({ans[nod-1],nod});
                }
            }
        }

        for(int i=0;i<n;i++){
            if(i==k-1)continue;
            if(ans[i]==1e9) return -1;
        }
        int maxi=*max_element(ans.begin(),ans.end());
        return maxi;
    }
};