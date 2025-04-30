class Solution {
public:
    struct trie {
        bool isend;
        trie* child[26];
    };

    trie*
    getnode() {
        trie* node = new trie();
        node->isend = 0;
        for (int i = 0; i < 26; i++)
            node->child[i] = NULL;

        return node;
    }

     trie* root;

    void insert(string &word) {
        trie* node = root;
        int n = word.size();

        for (int i = 0; i < n; i++) {
            int ch_idx = word[i] - 'a';
            if (node->child[ch_idx] == NULL)
                node->child[ch_idx] = getnode();

            node = node->child[ch_idx];
        }
        node->isend=1;
    }

    string search(string &word){
         trie* node = root;
        int n = word.size();

        for (int i = 0; i < n; i++){
             int ch_idx = word[i] - 'a';
             if (node->child[ch_idx] == NULL)
             return word;
             else 
             node = node->child[ch_idx];
             if(node->isend==1) return word.substr(0, i+1);
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
       root=getnode();
        int n = dictionary.size();

        for (int i = 0; i < n; i++)
            insert(dictionary[i]);

        stringstream ss(sentence);
        string word;

        string res;

        while(getline(ss, word, ' '))
        res+=search(word)+" ";

        res.pop_back();
        
        return res;
    }
};