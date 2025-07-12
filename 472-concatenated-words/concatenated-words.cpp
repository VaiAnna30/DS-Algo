class Solution {
public:
    bool func(unordered_set<string>& s,
              const string& word,
              int index,
              vector<int>& dp) {
        int n = word.size();
        if (index == n) 
            return true;
        
        if (dp[index] != -1) 
            return dp[index];
        for (int end = index + 1; end <= n; ++end) {
            if (s.count(word.substr(index, end - index)) &&
                func(s, word, end, dp)) {
                return dp[index] = 1;
            }
        }
        return dp[index] = 0;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n=words.size();
        unordered_set<string>s={words.begin(),words.end()};
        vector<string>ans;
        for(int i=0;i<n;i++){
            s.erase(words[i]);
            vector<int>dp(words[i].size()+1,-1);
            if(func(s,words[i],0,dp))ans.push_back(words[i]);
            s.insert(words[i]);
        }
        return ans;
    }
};