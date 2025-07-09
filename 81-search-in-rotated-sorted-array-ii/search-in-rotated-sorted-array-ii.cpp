
class Solution {
public:
    bool find(vector<int>&nums,int l,int r,int target){
        int n=nums.size();
        while(r>=l){
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]>target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return false;
    }
    int pivotelement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])return i+1;
        }
        return -1;
    }
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot=pivotelement(nums);
        // cout<<pivot<<endl;
        if(pivot==-1){
            if(find(nums,0,n-1,target)) return true;
        }
        else{
            if(find(nums,0,pivot-1,target)) return true;
            if(find(nums,pivot,n-1,target)) return true;
        }
        return false;
    }
};