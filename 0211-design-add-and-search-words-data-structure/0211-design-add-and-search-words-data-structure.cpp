class WordDictionary {
  private:
    struct Node {
        bool status;
        Node *child[26];

        Node() {
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

  public:
    Node *root;

    WordDictionary() { root = new Node(); }

    void addWord(std::string word) {
        int n = word.size(), i = 0;
        Node *temp = root;
        for (; i < n && temp->child[word[i] - 'a']; i++) {
            temp = temp->child[word[i] - 'a'];
        }
        for (; i < n; i++) {
            temp->child[word[i] - 'a'] = new Node();
            temp = temp->child[word[i] - 'a'];
        }

        temp->status = true;
    }

    bool helper(std::string &word, int i, Node *node) {
        if(word.size()  - 1 == i && word[i] == '.') {
            return true;
        }

        for (; i < word.size(); i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (!node->child[j] || !helper(word, i + 1, node->child[j])) {
                        continue;
                    }
                    return true;
                }
                return false;
            }

            if (!node->child[word[i] - 'a']) {
                return false;
            }
            node = node->child[word[i] - 'a'];
        }

        if(word[i] == '.') {
            return true;
        }
        return node->status;
    }

    bool search(std::string word) { return helper(word, 0, root); }
};
