class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n,-1);
        stack<int> s;
        for (int i = 2 * n - 1; i >= 0; i--) {
            int index = i % n;

            while (!s.empty() && s.top() <= nums[index]) {
                s.pop();
            }

            if (i<n){
                if (!s.empty()){
                    v[index]=s.top();
                }
            }
            s.push(nums[index]);
        }
        return v;
    }
};
