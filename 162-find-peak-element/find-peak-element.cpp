class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        int l=0,r=n-1;
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[mid-1]){
                l=mid;
            }else{
                r=mid;
            }
        }
        if(nums[l]>nums[l-1]&&nums[l]>nums[l+1]) return l;
        if(nums[r]>nums[r-1]&&nums[r]>nums[r+1]) return r;
        return 0;
    }
};