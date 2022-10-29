class TrieNode
{
public:
    TrieNode* child[26];
    bool is_word;
    
    TrieNode(){
        for(int i=0;i<26;i++)
            child[i] = 0;
        is_word = false;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
         root = new TrieNode();
    }
    
    void insert(string s) {
        TrieNode* p = root;
        for(int i=0;i<s.length();i++){
            if(p->child[s[i]-'a']==NULL)
                p->child[s[i]-'a'] = new TrieNode();
            p = p->child[s[i]-'a'];
        }
        p->is_word = true;
    }
    
    bool search(string word) {
        TrieNode* p = find(word);
        return p != NULL && p->is_word;
    }
    
    bool startsWith(string prefix) {
        return find(prefix) != NULL;
    }
    
private:
    TrieNode* find(string key){
        TrieNode* p = root;
        for(int i=0;i<key.size() && p!=NULL;i++){
            p = p->child[key[i]-'a'];
        }
        
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */