class Solution {
    vector<int> getLargestNum(vector<int> &nums, int k) {
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<n;i++) {
            while(!res.empty() && nums[i]>res.back() && n-i-1>=k-res.size())
                res.pop_back();
            if(res.size()<k)     
               res.push_back(nums[i]);      
        }
        return res;
    }

    vector<int> mergeNums(vector<int> &a, vector<int> &b) {
        vector<int> res;
        int i=0,j=0,m=a.size(),n=b.size();

        while(i<m || j<n) {
            if(i==m)
                res.push_back(b[j++]);
            else if(j==n || a[i]>b[j])
                res.push_back(a[i++]);
            else if(a[i]<b[j])
                res.push_back(b[j++]);   
            else {
                int k=0;
                while(i+k<m && j+k<n && a[i+k]==b[j+k])
                    k++;
                if(i+k>=m)
                   res.push_back(b[j++]);
                else if(j+k>=n)
                   res.push_back(a[i++]);
                else if(a[i+k]>b[j+k])
                   res.push_back(a[i++]);
                else
                   res.push_back(b[j++]);              
            }        
        }
        return res;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int>res(k,0);
        for(int k1=0;k1<=k;k1++) {
            int k2=k-k1;

            if(k1>nums1.size() || k2>nums2.size())
                continue;

            auto num1 = getLargestNum(nums1, k1);
            auto num2 = getLargestNum(nums2, k2);

            auto merged = mergeNums(num1, num2);
            if(merged>res)
                res=merged;
        }
        return res;
    }
};