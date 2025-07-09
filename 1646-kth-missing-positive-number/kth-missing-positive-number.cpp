class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>ans;
        set<int>s={arr.begin(),arr.end()};
        for(int i=1;i<=2000;i++){
            if(s.find(i)==s.end())ans.push_back(i);
        }
        return ans[k-1];
    }
};