class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        map<int,int>m;
        for(auto &a:tops)m[a]++;
        for(auto &a:bottoms)m[a]++;
        int maxfreq=0;
        int num=0;
        for(auto it:m){
            if(it.second>maxfreq){
                maxfreq=it.second;
                num=it.first;
            }
        }
        if(maxfreq<n)return -1;
        int count=0,change=0;
        for(int i=0;i<n;i++){
            if(tops[i]!=num&&bottoms[i]!=num)return -1;
            else if(tops[i]==num&&bottoms[i]==num)count++;
            else if(tops[i]==num)change++;
        }
        return min(change,n-change-count);
    }
};