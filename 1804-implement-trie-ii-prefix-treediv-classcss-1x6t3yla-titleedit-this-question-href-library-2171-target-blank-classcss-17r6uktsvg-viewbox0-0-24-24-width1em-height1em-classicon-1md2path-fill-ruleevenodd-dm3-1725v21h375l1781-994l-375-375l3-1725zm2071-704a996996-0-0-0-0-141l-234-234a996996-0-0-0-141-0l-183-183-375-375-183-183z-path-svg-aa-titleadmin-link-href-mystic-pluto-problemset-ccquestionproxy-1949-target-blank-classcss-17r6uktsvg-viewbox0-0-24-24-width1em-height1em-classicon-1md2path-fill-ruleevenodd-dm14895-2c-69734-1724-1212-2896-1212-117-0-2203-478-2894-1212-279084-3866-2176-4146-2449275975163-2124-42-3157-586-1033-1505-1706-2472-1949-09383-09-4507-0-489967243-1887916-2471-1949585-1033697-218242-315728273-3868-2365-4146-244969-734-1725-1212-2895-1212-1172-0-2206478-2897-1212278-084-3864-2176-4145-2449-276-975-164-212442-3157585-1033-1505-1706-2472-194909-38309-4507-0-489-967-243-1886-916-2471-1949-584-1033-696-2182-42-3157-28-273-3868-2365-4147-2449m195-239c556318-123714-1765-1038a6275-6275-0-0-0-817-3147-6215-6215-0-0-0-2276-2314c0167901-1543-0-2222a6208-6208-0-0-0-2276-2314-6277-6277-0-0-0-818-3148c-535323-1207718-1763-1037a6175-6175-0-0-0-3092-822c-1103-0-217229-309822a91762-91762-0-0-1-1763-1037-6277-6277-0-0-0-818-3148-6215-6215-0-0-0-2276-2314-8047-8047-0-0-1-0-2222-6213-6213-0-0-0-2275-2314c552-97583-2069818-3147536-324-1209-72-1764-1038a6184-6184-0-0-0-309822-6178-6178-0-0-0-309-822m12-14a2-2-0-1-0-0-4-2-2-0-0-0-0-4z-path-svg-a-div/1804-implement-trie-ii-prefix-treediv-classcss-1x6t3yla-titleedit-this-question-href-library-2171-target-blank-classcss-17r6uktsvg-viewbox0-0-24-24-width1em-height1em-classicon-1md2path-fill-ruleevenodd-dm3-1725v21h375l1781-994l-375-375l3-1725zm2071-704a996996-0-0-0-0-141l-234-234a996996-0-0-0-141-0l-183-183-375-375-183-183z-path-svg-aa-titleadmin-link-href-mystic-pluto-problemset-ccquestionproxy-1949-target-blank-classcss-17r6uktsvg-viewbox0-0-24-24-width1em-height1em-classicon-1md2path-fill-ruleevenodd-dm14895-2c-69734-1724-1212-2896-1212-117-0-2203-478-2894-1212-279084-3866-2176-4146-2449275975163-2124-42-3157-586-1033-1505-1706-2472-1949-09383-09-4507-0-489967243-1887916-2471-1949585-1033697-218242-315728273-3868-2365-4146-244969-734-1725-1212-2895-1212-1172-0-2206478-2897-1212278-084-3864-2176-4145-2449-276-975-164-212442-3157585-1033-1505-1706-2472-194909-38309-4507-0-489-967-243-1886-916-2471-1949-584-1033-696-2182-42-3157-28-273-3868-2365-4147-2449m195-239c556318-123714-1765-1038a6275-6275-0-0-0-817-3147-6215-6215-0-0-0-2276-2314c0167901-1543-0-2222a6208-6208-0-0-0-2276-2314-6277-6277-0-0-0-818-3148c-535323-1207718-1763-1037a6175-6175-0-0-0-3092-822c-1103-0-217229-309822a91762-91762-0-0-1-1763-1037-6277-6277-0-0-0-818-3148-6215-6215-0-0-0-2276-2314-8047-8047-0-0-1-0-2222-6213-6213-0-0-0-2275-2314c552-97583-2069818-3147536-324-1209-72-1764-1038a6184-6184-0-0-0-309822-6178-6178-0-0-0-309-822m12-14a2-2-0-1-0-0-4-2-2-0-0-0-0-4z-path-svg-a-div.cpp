class Trie {
public:
    struct Node{
        Node* links[26];
        int ct = 0;
        int st = 0;
    };
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(int i = 0 ; i < word.size() ;i++){
            if(temp -> links[word[i] - 'a'] == NULL)
            {
                temp -> links[word[i] - 'a'] = new Node();
            }
            temp = temp -> links[word[i] - 'a'];
            temp -> st = temp -> st + 1;
        }
        temp -> ct = temp -> ct + 1;
    }
    
    int countWordsEqualTo(string word) {
        Node* temp = root;
        for(int i = 0 ; i < word.size() ;i++){
            if(temp -> links[word[i] - 'a'] == NULL)
            {
                return 0;
            }
            temp = temp -> links[word[i] - 'a'];
        }
        return temp -> ct;
    }
    
    int countWordsStartingWith(string word) {
        Node* temp = root;
        for(int i = 0 ; i < word.size() ;i++){
            if(temp -> links[word[i] - 'a'] == NULL)
            {
                return 0;
            }
            temp = temp -> links[word[i] - 'a'];
        }
        return temp -> st;
    }
    
    void erase(string word) {
        Node* temp = root;
        for(int i = 0 ; i < word.size() ;i++){
            if(temp -> links[word[i] - 'a'] == NULL)
            {
                return ;
            }
            temp = temp -> links[word[i] - 'a'];
            temp -> st = temp -> st - 1;
        }
        temp -> ct = temp -> ct - 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */