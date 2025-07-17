class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        vector<int>nmin(n);
        stack<int>s;
        nmin[n-1]=n;
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            int val=arr[i];
            while(!s.empty()&&arr[s.top()]>=val){
                s.pop();
            }
            if(!s.empty())nmin[i]=s.top();
            else nmin[i]=n;
            s.push(i);
        }
        vector<int>pmin(n);
        stack<int>ss;
        pmin[0]=-1;
        ss.push(0);
        for(int i=1;i<n;i++){
            int val=arr[i];
            while(!ss.empty()&&arr[ss.top()]>=val){
                ss.pop();
            }
            if(!ss.empty())pmin[i]=ss.top();
            else pmin[i]=-1;
            ss.push(i);
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            long long leftCount = i - pmin[i];
            long long rightCount = nmin[i] - i;
            long long contrib = (arr[i] * (leftCount + rightCount -1 ));
            ans = max(ans , contrib);
        }
        return (int)ans;
    }
};