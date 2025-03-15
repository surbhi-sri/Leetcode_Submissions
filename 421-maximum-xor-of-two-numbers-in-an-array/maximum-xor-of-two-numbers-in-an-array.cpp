class Solution {
public:
    struct trieNode {
        trieNode* links[2] = {NULL, NULL};

        bool isContainKey(int bit) { return (links[bit] != NULL); }

        trieNode* get(int bit) { return links[bit]; }

        void put(int bit, trieNode* node) { links[bit] = node; }
    };

    class Trie {
    private:
        trieNode* root;

    public:
        Trie() { root = new trieNode(); }

        void insert(int num) {
            trieNode* node = root;

            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;

                if (!node->isContainKey(bit)) {
                    node->put(bit, new trieNode());
                }

                node = node->get(bit);
            }
        }

        int getMAX(int num) {

            trieNode* node = root;
            int max_num = 0;

            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                ;

                if (node->isContainKey(1 - bit)) {
                    max_num = max_num | (1 << i);
                    node = node->get(1 - bit);
                } else {
                    node = node->get(bit);
                }
            }

            return max_num;
        }
    };

    int findMaximumXOR(vector<int>& nums) {

        Trie trie;

        for (auto& it : nums)
            trie.insert(it);

        int maxi = 0;

        for (auto& it : nums)
            maxi = max(maxi, trie.getMAX(it));

        return maxi;
    }
};