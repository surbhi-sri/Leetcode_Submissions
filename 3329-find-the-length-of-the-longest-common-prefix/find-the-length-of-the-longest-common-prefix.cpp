class Solution {
public:
    struct trie {
      //  char digit;
        trie* child[10];
    };

    trie* getnode() {
        trie* node = new trie();
        for (int i = 0; i < 10; i++)
            node->child[i] = NULL;

        return node;
    }
trie* root;
    void insert(int num) {
        trie* crawler = root;

        string st = to_string(num);
        int n = st.size();

        for (int i = 0; i < n; i++) {
            int idx = st[i] - '0';
            if (crawler->child[idx] == NULL)
                crawler->child[idx] = getnode();

            crawler = crawler->child[idx];
        }
    }

    int search(int num) {
        trie* crawler = root;

        string st = to_string(num);
        int n = st.size();
        int i = 0;

        for (i = 0; i < n; i++) {
            int idx = st[i] - '0';
            if (crawler->child[idx] == NULL)
                return i;
            else
                crawler = crawler->child[idx];
        }
        return i;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
         root = getnode();

        for (int num : arr1) {
            insert(num);
        }

        int len = 0;
        for (int num : arr2) {
            int curr_len = search(num);
            len = max(len, curr_len);
        }
        return len;
    }
};