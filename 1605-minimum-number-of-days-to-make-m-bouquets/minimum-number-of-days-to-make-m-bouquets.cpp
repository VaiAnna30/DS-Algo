class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<(1LL*m*k)) return -1;
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int r=*max_element(bloomDay.begin(),bloomDay.end());

        auto valid=[&](int mid){
            int count=0;
            int c=0;
            
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    c++;
                    if(c==k){
                        count++;
                        c=0;
                    }
                }else{
                    c=0;
                }
            }

            if(count>=m) return true;
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