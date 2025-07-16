class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        priority_queue<int>pq(nums.begin(),nums.end());
        int maxa = 0;
        while(!pq.empty()){
            int temp = pq.top();
            pq.pop();
            if(pq.empty()) break;
            maxa = max(maxa,temp-pq.top());
        }
        return maxa;
    }
};