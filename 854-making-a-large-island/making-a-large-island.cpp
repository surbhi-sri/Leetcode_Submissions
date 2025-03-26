class Solution {
public:
    class DSU {
    public:
        vector<int> parent, size;

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

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        DSU ds(n * n);

        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int r = i + dr[k];
                        int c = j + dc[k];
     

                        if (r >= 0 && c >= 0 && r < n && c < n &&
                            grid[r][c] == 1) {
                            int node = i * n + j;
                            int adNode = r * n + c;

                            ds.unions(node, adNode);
                        }
                    }
                }
            }
        }
        int mx_area = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int area = 1;
                    for (int k = 0; k < 4; k++) {
                        int r = i + dr[k];
                        int c = j + dc[k];

                        if (r >= 0 && c >= 0 && r < n && c < n &&
                            grid[r][c] == 1) {
                            int parent = ds.find(r * n + c);
                            if (seen.find(parent) == seen.end()) {
                                area += ds.size[parent];
                                seen.insert(parent);
                            }
                        }
                    }
                    mx_area = max(mx_area, area);
                }
            }
        }

               
        return mx_area == 0 ? n * n : mx_area;
    }
};