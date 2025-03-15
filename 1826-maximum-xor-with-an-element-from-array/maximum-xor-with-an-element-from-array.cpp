class Solution {
public:
    struct trieNode {
        trieNode* links[2] = {NULL, NULL};

        bool isContainKey(int bit) { return links[bit] != NULL; }

        void put(int bit, trieNode* node) { links[bit] = node; }

        trieNode* get(int bit) { return links[bit]; }
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

        int get_max(int num) {
            trieNode* node = root;
            int max_num = 0;

            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;

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

   
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

       sort(begin(nums), end(nums));

       vector<pair<int, pair<int, int>>> oq;
       int q=queries.size();

       for(int i=0; i<q; i++)
        oq.push_back({queries[i][1], {queries[i][0], i}});
       
       sort(oq.begin(), oq.end());

         int ind=0, n=nums.size();

       vector<int> ans(q, 0);

        Trie trie;

        for(int i=0; i<q; i++){
            int m=oq[i].first;
            int x=oq[i].second.first;
            int qind=oq[i].second.second;

            while(ind< n && nums[ind]<=m){
                  trie.insert(nums[ind]); 
                  ind++;
            }

            if(ind==0) ans[qind]=-1;
            else ans[qind]=trie.get_max(x);

        }

  
        return ans;
    }
};