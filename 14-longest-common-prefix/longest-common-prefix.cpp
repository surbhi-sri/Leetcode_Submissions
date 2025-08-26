class Solution {
public:
    class TrieNode {
    public:
        char data;
        TrieNode* child[26];
        bool isEnd;
        int childCount;

        TrieNode(char ch) {
            data = ch;
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
            isEnd = 0;
            childCount=0;
        }
    };

    class trie {
        TrieNode* root;

    public:
        trie() { root = new TrieNode('\0'); }

        void insert(const string& s) {
            TrieNode* node = root;

            for (char c : s) {
                int idx = c - 'a';
                if (!node->child[idx]) {
                    node->child[idx] = new TrieNode(c);
                    node->childCount++;
                }

                node = node->child[idx];
            }
            node->isEnd = 1;
        }

        string LCP() {
            string prefix = "";
            TrieNode* node = root;
            while (node->childCount == 1 && node->isEnd == 0) {
                for (int i = 0; i < 26; i++) {
                    if (node->child[i]) {
                        node = node->child[i];
                        prefix.push_back(node->data);
                        break;
                    }
                }
            }
            return prefix;
        }
    };

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1)
            return strs[0];
        trie t;
        for (string& s : strs)
            t.insert(s);

        return t.LCP();
    }
};