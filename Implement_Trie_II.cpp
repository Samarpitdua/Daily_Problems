class Trie{

    public:
	struct Node
    {
      	Node *links[26];
        int ct = 0;
        int pref = 0;
    };
    Node* root;
    Trie(){
        root = new Node();
        // Write your code here.
    }

    void insert(string &word){
        Node *temp = root;
        for(int i = 0 ; i < word.size() ;i++)
        {
            if(!temp -> links[word[i] - 'a'])
            {
                Node* newnode = new Node();
                temp -> links[word[i] - 'a'] = newnode;
            }
            temp -> pref += 1;
            temp = temp -> links[word[i] - 'a'];
            
        }
        temp -> pref += 1;
        temp -> ct +=  1;
        // Write your code here.
    }

    int countWordsEqualTo(string &word){
        Node *temp = root;
        for(int i = 0 ; i < word.size() ;i++)
        {
            if(!temp -> links[word[i] - 'a'])
            {
                return 0;
            }
            temp = temp -> links[word[i] - 'a'];
        }
        return temp -> ct;
        // Write your code here.
    }

    int countWordsStartingWith(string &word){
        Node *temp = root;
        for(int i = 0 ; i < word.size() ;i++)
        {
            if(!temp -> links[word[i] - 'a'])
            {
                return 0;
            }
            temp = temp -> links[word[i] - 'a'];
        }
        return temp -> pref;
        // Write your code here.
    }

    void erase(string &word){
        Node *temp = root;
        for(int i = 0 ; i < word.size() ;i++)
        {
            temp -> pref -= 1;
            temp = temp -> links[word[i] - 'a'];
        }
        temp -> pref -= 1;
        temp -> ct -= 1;
        // Write your code here.
    }
};
