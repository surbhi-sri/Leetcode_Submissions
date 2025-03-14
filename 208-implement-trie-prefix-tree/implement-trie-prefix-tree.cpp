struct trieNode {
    bool isEndOfWord = 0;
    trieNode* child[26];

    bool containKey(char ch) { return (child[ch - 'a'] != NULL); }

    void put(char ch, trieNode* node) { child[ch - 'a'] = node; }

    trieNode* get(char ch) { return child[ch - 'a']; }

    void setEnd() {  isEndOfWord = 1; }

    bool isEnd() { return isEndOfWord; }
};

class Trie {
private:
    trieNode* root;

public:
    Trie() { root = new trieNode(); }

    void insert(string word) {
        trieNode* node = root;

        for (char ch : word) {

            if (!node->containKey(ch)) {
                node->put(ch, new trieNode());
            }

            node = node->get(ch);
        }

        node->setEnd();
    }

    bool search(string word) {

        trieNode* node = root;

        for (char ch : word) {

            if (!node->containKey(ch)) {
                return 0;
            }

            node = node->get(ch);
        }

        return node->isEnd();
    }

    bool startsWith(string prefix) {

        trieNode* node = root;

        for (char ch : prefix) {

            if (!node->containKey(ch)) {
                return 0;
            }

            node = node->get(ch);
        }

        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */