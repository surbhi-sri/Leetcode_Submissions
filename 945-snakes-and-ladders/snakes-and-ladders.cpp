class Solution {
public:
    int n;

    pair<int, int> getCoord(int num) {
        int rt = (num - 1) / n;
        int rb = (n - 1) - rt;

        int col = (num - 1) % n;

        if (rt % 2 == 1)
            col = (n - 1) - col;

        return {rb, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        queue<int> q;
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        vis[n - 1][0] = 1;
        q.push(1);

        int step = 0;

        while (!q.empty()) {
            int N = q.size();

            while (N--) {
                int x = q.front();
                q.pop();
                if (x == n * n)
                    return step;

                for (int k = 1; k <= 6; k++) {
                    int val = x + k;

                    if (val > n * n)
                        break;

                    pair<int, int> coord = getCoord(val);
                    int r = coord.first;
                    int c = coord.second;

                    if (vis[r][c] == 1)
                        continue;

                    vis[r][c] = 1;

                    if (board[r][c] == -1)
                        q.push(val);
                    else
                        q.push(board[r][c]);
                }
            }
            step++;
        }
        return -1;
    }
};