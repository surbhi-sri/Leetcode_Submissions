class Solution {
public:
    struct trie {
        trie* child[26];
        bool isend = 0;
    };

    trie* getnode() {
        trie* node = new trie();
        for (int i = 0; i < 26; i++)
            node->child[i] = NULL;

        node->isend = 0;

        return node;
    }

    trie* root;

    void insert(string& s) {
        trie* crawler = root;

        for (char ch : s) {
            int idx = ch - 'a';
            if (crawler->child[idx] == NULL)
                crawler->child[idx] = getnode();

            crawler = crawler->child[idx];
        }
        crawler->isend = 1;
    }

    bool search(string& s) {
        trie* crawler = root;

        for (char ch : s) {
            int idx = ch - 'a';
            if (crawler->child[idx] == NULL)
                return 0;
            crawler = crawler->child[idx];
            if (crawler->isend == 1)
                return 1;
        }
        return 0;
    }

    int prefixCount(vector<string>& words, string pref) {
        root = getnode();
        insert(pref);

        int cnt = 0;

        for (string word : words) {
            cnt += search(word);
        }

        return cnt;
    }
};