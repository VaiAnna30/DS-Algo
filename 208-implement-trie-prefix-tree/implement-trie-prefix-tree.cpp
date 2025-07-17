struct Node{
    Node *link[26];
    bool flag;
    Node(){
        flag=false;
        for(int i=0;i<26;i++)link[i]=nullptr;
    }
    bool containskey(char ch){
        return (link[ch-'a']!=nullptr);
    }
    void put(char ch,Node* node){
        link[ch-'a']=node;
    }
    Node* get(char ch){
        return link[ch-'a'];
    }
    void setend(){
        flag=true;
    }
    bool isend(){
        return flag;
    }
};
class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node * node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setend();
    }
    
    bool search(string word) {
        Node* node=root;
        for(char ch:word){
            if(!node->containskey(ch)){
                return false;
            }
            node=node->get(ch);
        }
        return node->isend();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(char ch:prefix){
            if(!node->containskey(ch)){
                return false;
            }
            node=node->get(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */