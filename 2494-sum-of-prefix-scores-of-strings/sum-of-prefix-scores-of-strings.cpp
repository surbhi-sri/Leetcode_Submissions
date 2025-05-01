class Solution {
public:
    struct trie {
        int cntp = 0;
        trie* child[26];
    };

    trie* root;

    trie* getnode() {
        trie* node = new trie();
        for (int i = 0; i < 26; i++)
            node->child[i] = NULL;
        node->cntp = 0;

        return node;
    }

    void insert(string s) {
        int n = s.size();
        trie* crwaler = root;
        for (int i = 0; i < n; i++) {
            int ind = s[i] - 'a';

            if (crwaler->child[ind] == NULL)
                crwaler->child[ind] = getnode();
            crwaler->child[ind]->cntp++;
            crwaler = crwaler->child[ind];
        }
    }

    int countprefix(string s) {
        int n = s.size();
        int cnt = 0;
        trie* crwaler = root;
        for (int i = 0; i < n; i++) {
            int ind = s[i] - 'a';
            cnt += crwaler->child[ind]->cntp;
            crwaler = crwaler->child[ind];
        }

        return cnt;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        root = getnode();

        for (string& s : words)
            insert(s);

        vector<int> ans;

        for (string& s : words) {
            int cnt = countprefix(s);
            ans.push_back(cnt);
        }
        return ans;
    }
};