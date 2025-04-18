class Solution {
public:
    vector<string> res;
    int m, n;

    struct trieNode {
        bool end_of_word;
        string word;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->end_of_word = 0;
        newNode->word = "";

        for (int i = 0; i < 26; i++)
            newNode->children[i] = 0;

        return newNode;
    }

    void insert(trieNode* root, string words) {
        trieNode* crawler = root;

        for (int i = 0; i < words.size(); i++) {
            char ch = words[i];

            if (crawler->children[ch - 'a'] == NULL)
                crawler->children[ch - 'a'] = getNode();

            crawler = crawler->children[ch - 'a'];
        }
        crawler->end_of_word = 1;
        crawler->word = words;
    }

    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    void findWord(int i, int j, trieNode* root, vector<vector<char>>& board) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return;

        if (board[i][j] == '$' || root->children[board[i][j] - 'a'] == NULL)
            return;

        root = root->children[board[i][j] - 'a'];
        if (root->end_of_word == 1) {
            res.push_back(root->word);
            root->end_of_word = 0;
        }

        char temp = board[i][j];
        board[i][j] = '$';

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            findWord(nr, nc, root, board);
        }

        board[i][j] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        n = board.size();
        m = board[0].size();

        trieNode* root = getNode();

        for (string& word : words) {
            insert(root, word);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch = board[i][j];

                if (root->children[ch - 'a'] != NULL) {
                    findWord(i, j, root, board);
                }
            }
        }

        return res;
    }
};