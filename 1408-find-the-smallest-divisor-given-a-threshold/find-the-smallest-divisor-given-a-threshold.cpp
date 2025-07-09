class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1;
        int r=1e6;
        
        auto valid=[&](int mid){
            int sum=0;
            for(auto &a:nums){
                sum+=((a+mid-1)/mid);
            }
            if(sum<=threshold)return true;
            return false;
        };

        while(r-l>1){
            int mid=l+(r-l)/2;
            if(valid(mid)){
                r=mid;
            }else{
                l=mid;
            }
        }
        if(valid(l)) return l;
        return r;
    }
};