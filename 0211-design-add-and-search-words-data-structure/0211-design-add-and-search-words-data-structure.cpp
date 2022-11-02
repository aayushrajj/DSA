class TrieNode{
public:
    TrieNode * child[26];
    bool is_word;
    
    TrieNode(){
        for(int i=0;i<26;i++)
            child[i] = 0;
        is_word = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* p = root;
        for(int i=0;i<word.length();i++){
            if(p->child[word[i]-'a'] == NULL)
                p->child[word[i]-'a'] = new TrieNode();
            p = p->child[word[i]-'a'];
        }
        
        p->is_word = true;
    }
    
    bool search(string word) {
        return search(word,0,root);
    }
    
private:
    bool search(string &key,int pos,TrieNode* root){
        if(pos==key.length())
            return root->is_word;
        
        if(key[pos] != '.'){
            root = root->child[key[pos]-'a'];
            return root ? search(key,pos+1,root) : false;
        }
        
        for(int i=0;i<26;i++){
            if(root->child[i] && search(key,pos+1,root->child[i]))
                return true;
        }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */