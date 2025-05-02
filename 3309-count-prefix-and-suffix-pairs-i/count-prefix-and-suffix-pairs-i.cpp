struct trie {
    trie* child[26];
    bool isend = 0;
};

trie* getnode() {
    trie* node = new trie();
    node->isend = 0;

    for (int i = 0; i < 26; i++)
        node->child[i] = NULL;

    return node;
}

class trienode {
public:
    trie* root;

    trienode() { root = getnode(); }

    void insert(string s) {
        trie* crawler = root;

        int n = s.size();
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (crawler->child[idx] == NULL)
                crawler->child[idx] = getnode();

            crawler = crawler->child[idx];
        }
        crawler->isend = 1;
    }

    bool search(string s) {
        trie* crawler = root;

        int n = s.size();
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (crawler->child[idx] == NULL)
                return 0;

            crawler = crawler->child[idx];
        }
        return 1;
    }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {

        int cnt = 0;
        int n = words.size();

        for (int j = 1; j < n; j++) {

            trienode root1;
            trienode root2;

            string temp = words[j];
            reverse(temp.begin(), temp.end());

            root1.insert(words[j]);
            root2.insert(temp);

            for (int i = 0; i < j; i++) {

                if (words[i] > words[j])
                    continue;

                string rev = words[i];
                reverse(rev.begin(), rev.end());

                if (root1.search(words[i]) == 1 && root2.search(rev) == 1)
                    cnt++;
            }
        }

        return cnt;
    }
};
