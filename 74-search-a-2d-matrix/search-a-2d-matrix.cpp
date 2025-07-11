class Solution {
public:
    bool searchMatrix(vector<vector<int>>&v,int a){
        int m=v.size();
        int n=v[0].size();
        if(a<v[0][0]) return false;
        if(a>v[m-1][n-1]) return false;
        v.push_back({INT_MAX});
        auto valid=[&](int mid){
            if(v[mid][0]<=a&&a<v[mid+1][0]){
                return 1;
            }else if(v[mid][0]>a){
                return 2;
            }else return 3;
        };

        int l=0,r=m-1;
        int index=-1;
        while(r>=l){
            int mid=l+(r-l)/2;
            int check=valid(mid);
            if(check==1){
                index=mid;
                break;
            }else if(check==2){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        if(index==-1) return false;
        vector<int>&vec=v[index];
        int ind=lower_bound(vec.begin(),vec.end(),a)-vec.begin();
        if(ind<n&&vec[ind]==a)return true;
        return false;

    }
};