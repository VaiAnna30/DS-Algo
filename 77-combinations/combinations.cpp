class Solution {
public:
    void sub(vector<vector<int>>& p ,vector<int>& arr,int index,int k,int n){
        if(arr.size()==k){
            p.push_back(arr);
            return;
        }

        for(int i=index; i<n; i++){
            arr.push_back(i+1);
            sub(p,arr,i+1,k,n);
            arr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> nums;
        vector<int> arr;
        sub(nums,arr,0,k,n);
        return nums;   
    }
};