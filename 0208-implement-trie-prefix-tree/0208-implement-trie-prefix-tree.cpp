struct Node {
    bool end;
    Node* child[26];

    Node() {
        end = false;
        for(int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node(); 
    }
    
    void insert(std::string word) {
        int n = word.size(), i = 0;
        Node *temp =  root;
        for(; i < n && temp->child[word[i] - 'a']; i++) {
            temp = temp->child[word[i] - 'a'];
        }
        for(; i < n; i++) {
            temp->child[word[i] - 'a'] = new Node();
            temp = temp->child[word[i] - 'a'];
        }

        temp->end = true;
    }
    
    bool search(std::string word) {
        int n = word.size();
        Node *temp =  root;
        for(int i = 0; i < n; i++) {
            if(!temp->child[word[i] - 'a']) {
                return false;
            }
            temp = temp->child[word[i] - 'a'];
        }
        return temp->end;
    }
    
    bool startsWith(std::string prefix) {
        int n = prefix.size();
        Node *temp =  root;
        for(int i = 0; i < n; i++) {
            if(!temp->child[prefix[i] - 'a']) {
                return false;
            }
            temp = temp->child[prefix[i] - 'a'];
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
