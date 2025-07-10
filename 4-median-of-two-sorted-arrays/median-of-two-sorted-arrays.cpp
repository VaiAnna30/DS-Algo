class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double>ans;
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0;
        while(i<n&&j<m){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            ans.push_back(nums2[j]);
            j++;
        }
        if(ans.size()%2==0){
            double val=ans[(m+n)/2]+ans[((m+n)/2)-1];
            return val/2;
        }
        return ans[(m+n)/2];
    }
};