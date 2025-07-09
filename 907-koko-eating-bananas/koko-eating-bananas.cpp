class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1,r=*max_element(piles.begin(),piles.end());
        auto valid=[&](int mid){
            int count=0;
            for(int i=0;i<piles.size();i++){
                count+=((piles[i]+mid-1)/mid);
                if(count>h)return false;
            }
            return true;
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