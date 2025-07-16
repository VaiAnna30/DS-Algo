class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>trip;

        unordered_map<int,int>m;
        for(auto &a:nums)m[a]++;
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            int val1=nums[i];
            m[val1]--;
            for(int j=i+1;j<n;j++){
                int val2=nums[j];
                m[val2]--;
                sum=val1+val2;
                if(m[-sum]>0){
                    vector<int>vv={val1,val2,-(sum)};
                    sort(vv.begin(),vv.end());
                    trip.push_back(vv);
                }
                m[val2]++;
            }
            m[val1]++;
        }
        sort(trip.begin(), trip.end());
        trip.erase(unique(trip.begin(), trip.end()), trip.end());
        return trip;
    }
};
/*
-4 -1 0 1 2
 1  2 1 1 1
*/