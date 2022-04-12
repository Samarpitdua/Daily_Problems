class Trie {
public:
    struct Node
    {
        Node* link[26];
        bool flag = false;
    };
    Node *root;
    Trie()
    {
       root = new Node();
    }
    void insert(string word) {
        Node *temp = root;
        for(int i = 0 ; i < word.size() ; i++)
        {
            if(temp -> link[word[i] - 'a'] == NULL)
            {
                Node *newnode = new Node();
                temp -> link[word[i] - 'a'] = newnode;
            }
            temp = temp -> link[word[i] - 'a'];
        }
        temp -> flag = true;
    }
    
    bool search(string word) {
        Node *temp = root;
        for(int i = 0 ; i < word.size() ;i++)
        {
            if(temp -> link[word[i] - 'a'] == NULL)
                return false;
            temp = temp -> link[word[i] - 'a'];    
        }
        return temp -> flag;
    }
    
    bool startsWith(string prefix) {
        Node *temp = root;
        for(int i = 0 ; i < prefix.size() ;i++)
        {
            if(temp -> link[prefix[i] - 'a'] == NULL)
                return false;
            temp = temp -> link[prefix[i] - 'a'];
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