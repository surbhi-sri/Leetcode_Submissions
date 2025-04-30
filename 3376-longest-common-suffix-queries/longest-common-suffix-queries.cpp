class Solution {
public:
    class trienode {
    public:
        int idx;
        trienode* child[26];

        trienode() {
            idx = -1;
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };

    class trie {
    public:
        trienode* root;
        vector<int> ans;

        trie() { root = new trienode(); }
        ~trie() { freeTrie(root); }

        void insert(int ind, vector<string>& wordsContainer) {
            trienode* node = root;
            string word = wordsContainer[ind];
            int n = word.size();

            for (int i = n - 1; i >= 0; i--) {
                int ch_idx = word[i] - 'a';

                if (node->child[ch_idx] == NULL) {
                    node->child[ch_idx] = new trienode();
                    node->child[ch_idx]->idx = ind;
                }

                node = node->child[ch_idx];

                if (wordsContainer[ind].size() <
                    wordsContainer[node->idx].size())
                    node->idx = ind;
            }
        }

        void search(string& word, int smallest_idx) {
            int n = word.size();
            trienode* node = root;

                if (node->child[word[n-1] - 'a'] == NULL) {
                ans.push_back(smallest_idx);
                return;
            }
            else {
                for (int i = n - 1; i >= 0; i--) {
                    int ch_idx = word[i] - 'a';
                    if (node->child[ch_idx] == NULL) {
                        ans.push_back(node->idx);
                        return;
                    }
                    node = node->child[ch_idx];
                }
                ans.push_back(node->idx);
            }
        }

    private:
        void freeTrie(trienode* node) {
            if (!node)
                return;

            for (int i = 0; i < 26; i++) {
                if (node->child[i])
                    freeTrie(node->child[i]);
            }
            delete node;
        }
    };

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie* tr = new trie();
        int n = wordsContainer.size();
        int m = wordsQuery.size();
        int em = 0, size = INT_MAX;

        for (int i = 0; i < n; i++) {
            tr->insert(i, wordsContainer);
            if (wordsContainer[i].size() < size) {
                size = wordsContainer[i].size();
                em = i;
            }
        }

        for (int i = 0; i < m; i++) {
            tr->search(wordsQuery[i], em);
        }

        vector<int> res = tr->ans;
        delete tr;

        return res;
    }
};