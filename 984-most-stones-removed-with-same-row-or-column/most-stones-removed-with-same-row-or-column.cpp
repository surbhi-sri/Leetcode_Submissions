class Solution {
public:
    class DSU {
    public:
        vector<int> parent, size;

        DSU(int n) {
            parent.resize(n + 1);
            size.resize(n + 1, 1);

            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x)
                return x;

            return parent[x] = find(parent[x]);
        }

        void unions(int x, int y) {
            int rootx = find(x);
            int rooty = find(y);

            if (rootx != rooty) {
                if (size[rootx] < size[rooty]) {
                    parent[rootx] = rooty;
                    size[rooty] += size[rootx];
                } else {
                    parent[rooty] = rootx;
                    size[rootx] += size[rooty];
                }
            }
        }
    };

    int removeStones(vector<vector<int>>& stones) {

        int max_row = 0;
        int max_col = 0;
        int n = stones.size();

        for (auto it : stones) {
            max_row = max(max_row, it[0]);
            max_col = max(max_col, it[1]);
        }

        DSU ds(max_row + max_col + 1);
        unordered_map<int, int> stoneNode;

        for (auto it : stones) {
            int row = it[0];
            int col = it[1] + max_row + 1;

            ds.unions(row, col);
            stoneNode[row] = 1;
            stoneNode[col] = 1;
        }

        int cnt = 0;

        for (auto it : stoneNode) {
            if (ds.find(it.first) == it.first)
                cnt++;
        }

        return n - cnt;
    }
};