class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>ans;
        unordered_map<long long,int>m;
        for(auto &a:nums)m[a]++;
        for(int i=0;i<n-3;i++){
            long long val1=nums[i];
            m[val1]--;
            for(int j=i+1;j<n-2;j++){
                long long val2=nums[j];
                m[val2]--;
                for(int k=j+1;k<n-1;k++){
                    long long val3=nums[k];
                    m[val3]--;
                    long long sum=(target)-((val1+val2+val3));
                    if(m[sum]>0){
                        vector<int>vv={(int)val1,(int)val2,(int)val3,(int)sum};
                        sort(vv.begin(),vv.end());
                        ans.push_back(vv);
                    }
                    m[val3]++;
                }
                m[val2]++;
            }
            m[val1]++;
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};