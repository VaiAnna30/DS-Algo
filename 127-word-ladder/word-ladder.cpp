class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s={wordList.begin(),wordList.end()};
        queue<pair<string,int>>q;
        q.push({beginWord,1});

        while(!q.empty()){
            string str=q.front().first;
            int dist=q.front().second;
            if(str==endWord) return dist;
            q.pop();
            for(int i=0;i<str.size();i++){
                char original=str[i];
                for(char c='a';c<='z';c++){
                    str[i]=c;
                    if(s.count(str)!=0){
                        q.push({str,dist+1});
                        s.erase(str);
                    }
                }
                str[i]=original;
            }
        }
        return 0;
    }
};