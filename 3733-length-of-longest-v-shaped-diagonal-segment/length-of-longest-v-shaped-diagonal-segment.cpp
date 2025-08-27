class Solution {
public:
   int dp[501][501][4][2];
    int di[4] = {1, 1, -1, -1};
    int dj[4] = {1, -1, -1, 1};
    int n, m;
    vector<vector<int>> g;
    bool isValid(int x, int y){
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
    }
    int rec(int i, int j, int dir, int left)
    {
        if(dp[i][j][dir][left]!=-1) return dp[i][j][dir][left];
        int ans = 0;
        if(g[i][j]%2==0){
            ans=1;
            int ni = i+di[dir];
            int nj = j+dj[dir];
            if(isValid(ni, nj))
            {
                if(g[ni][nj]+g[i][j]==2)
                {
                    ans += rec(ni, nj, dir, left);
                }
            }
            if(left){
                int k = (dir+1)%4;
                int ni = i+di[k];
                int nj = j+dj[k];
                if(isValid(ni, nj))
                {
                    if(g[ni][nj]+g[i][j]==2)
                    {
                        ans = max(ans, 1+rec(ni, nj, k, left-1));
                    }
                }
            }
        }
        return dp[i][j][dir][left]=ans;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        g=grid;
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    ans = max(ans, 1);
                    for(int k=0; k<4; k++)
                    {
                        int ni = i+di[k], nj = j+dj[k];
                        if(isValid(ni, nj) && grid[ni][nj]==2)
                            ans = max(ans, 1+rec(ni, nj, k, 1));
                    }
                }
            }
        }
        return ans;
    }
};