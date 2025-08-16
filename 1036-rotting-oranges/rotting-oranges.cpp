class Solution {
public:

  int dr[4]={-1, 0, 1, 0};
  int dc[4]={0, -1, 0, 1};

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                }
            }
        }

vector<vector<int>> temp=grid;
int t=0;

        while(1){
         int size=q.size();

         for(int i=0; i<size; i++){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            vis[r][c]=1;
           
             for(int j=0; j<4; j++){
                int nr=r+dr[j];
                int nc=c+dc[j];

                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && temp[nr][nc]==1){
                   
                    temp[nr][nc]=2;
                    q.push({nr, nc});
                }
             }
            
         }

         if(q.empty()) break;
         else t++;
        }

          for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(temp[i][j]==1){
                   return -1;
                }
            }
        }

        return t;

    }
};