class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp=a;
        int count=1;
        while(temp.size()<b.size()){
            count++;
            temp+=a;
        }

        if(temp.find(b)!=string::npos) return count;
        count++;
        temp+=a;
        if(temp.find(b)!=string::npos) return count;
        return -1;
    }
};