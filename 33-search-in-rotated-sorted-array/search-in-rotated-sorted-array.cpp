class Solution {
public:
    int find(vector<int>&nums,int target,int pivot){
        int n=nums.size();
        int l=0,r=n-1;
        if (n == 0) return -1;
        if(n==1) return (nums[0]==target)?0:-1;
        if(pivot!=0&&target>nums[pivot-1]) return -1;
        if(target<=nums[n-1])l=pivot;
        else r=pivot-1;
        while(r>=l){
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return -1;
    }
    int pivotelement(vector<int>&nums){
        int n=nums.size();
        int l=0,r=n-1;
        if (nums[l] <= nums[r]) return 0;
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid;
            }else{
                r=mid;
            }
        }
        if(nums[l]<nums[r]) return l;
        return r;
    }
    int search(vector<int>& nums, int target) {
        int pivot=pivotelement(nums);
        return find(nums,target,pivot);
    }
};