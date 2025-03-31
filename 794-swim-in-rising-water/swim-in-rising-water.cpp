class Solution {
public:
    class DSU {

        vector<int> parent, size;

    public:
        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);

            for (int i = 0; i < n; i++)
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

                if (size[x] < size[y]) {
                    parent[rootx] = rooty;
                    size[rooty] += size[rootx];
                } else {
                    parent[rooty] = rootx;
                    size[rootx] += size[rooty];
                }
            }
        }
    };

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int total_grid = n * n;
        DSU ds(total_grid);

        vector<pair<int, pair<int, int>>> cell;

            for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cell.push_back({grid[i][j], {i, j}});
            }
        }

        vector<vector<int>> vis(n, vector<int>(n, 0));

        sort(cell.begin(), cell.end());

        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (auto& cell : cell) {
            int elevation = cell.first;
            int r = cell.second.first;
            int c = cell.second.second;

            int index = r * n + c;

            vis[r][c] = 1;

            for(int i=0; i<4; i++){
                int nr = dr[i] + r;
                int nc = dc[i] + c;

                if(nr<n && nr>=0 && nc<n && nc>=0 && vis[nr][nc]){
                  int neighour_index= nr*n+nc;
                  ds.unions(index, neighour_index);
                }
            }

            if(ds.find(0)==ds.find(n*n-1)) return elevation;
        }

        return 0;
    }
};