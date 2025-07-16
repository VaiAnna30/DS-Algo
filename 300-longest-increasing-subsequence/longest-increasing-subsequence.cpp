class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res;
        int n=nums.size();
        res.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(res.back()>=nums[i]){
                int index=lower_bound(res.begin(),res.end(),nums[i])-res.begin();
                res[index]=nums[i];
            }else{
                res.push_back(nums[i]);
            }
        }
        return res.size();
    }
};