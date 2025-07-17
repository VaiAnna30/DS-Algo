class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        stack<int>s;
        vector<int>ans(n2);
        int i=n2-1;
        while(i>=0){
            if(s.empty()){
                ans[i]=-1;
                s.push(nums2[i]);
                i--;
            }else{
                if(s.top()>nums2[i]){
                    ans[i]=s.top();
                    s.push(nums2[i]);
                    i--;
                    continue;
                }
                while(s.top()<nums2[i]){
                    s.pop();
                    if(s.empty()){
                        ans[i]=-1;
                        break;
                    }
                }
                if(ans[i]!=-1) ans[i]=s.top();
                s.push(nums2[i]);
                i--;
            }
        }
        vector<int>result;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    result.push_back(ans[j]);
                    break;
                }
            }
        }
        return result;
    }
};