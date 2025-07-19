class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>ans;
        sort(folder.begin(),folder.end());
        string prev="";
        for(int i=0;i<folder.size();i++){
            if(prev.empty()||folder[i].find(prev+"/")!=0){
                ans.push_back(folder[i]);
                prev=folder[i];
            }
        }
        return ans;
    }
};