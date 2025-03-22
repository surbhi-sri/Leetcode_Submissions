class Solution {
public:
    void bfs(int i, vector<vector<int>>& adj, vector<bool>& vis, int &v, int &e) {
      queue<int> q;
      q.push(i);

      while(!q.empty()){
        int node=q.front();
        vis[node]=1;;
        q.pop();
        v++;

        for(auto it: adj[node]){
           e++;
           if(!vis[it]) bfs(it, adj, vis, v, e);
        }
      }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& edges : edges) {

            adj[edges[0]].push_back(edges[1]);
            adj[edges[1]].push_back(edges[0]);
        }

        vector<bool> vis(n, 0);
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int v = 0;
                int e = 0;
                bfs(i, adj, vis, v, e);
                if (v * (v - 1) == e)
                    res++;
            }
        }

        return res;
    }
};