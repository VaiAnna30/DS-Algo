class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>list(numCourses);
        
        vector<int>indegree(numCourses);
        for(auto &a:prerequisites){
            list[a[1]].push_back(a[0]);
            indegree[a[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            for(auto &a:list[val]){
                indegree[a]--;
                if(indegree[a]==0)q.push(a);
            }
            ans.push_back(val);
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};

/*
[0,1]
[0.4]
[1,4]
1->0
4->0
4->1
4->1->0
*/