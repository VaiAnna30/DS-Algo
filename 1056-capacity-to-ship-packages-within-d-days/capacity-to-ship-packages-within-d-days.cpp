class Solution {
public:
    int shipWithinDays(vector<int>& weight, int days) {
        int n=weight.size();

        auto valid=[&](int mid){
            int sum=weight[0];
            int count=0;
            for(int i=1;i<n;i++){
                if(weight[i]>mid) return false;
                if(sum+(weight[i])<=mid){
                    sum+=weight[i];
                }
                else{
                    count++;
                    sum=weight[i];
                }
            }
            if(sum>0)count++;
            if(count<=days) return true;
            return false;
        };

        int l=*max_element(weight.begin(),weight.end());
        int r=1e9;
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