class Solution {
public:
    int dfs(int curr, vector<vector<int>>& adj, int k, int parent) {
       if(k<0) return 0;

       int cnt=1;

       for(int &it:adj[curr]){
        if(it!=parent)
        cnt +=dfs(it, adj, k-1, curr);
       }

       return cnt;
    }

    vector<int> findCount(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> res(n);

        for (int i = 0; i < n; i++)
            res[i] = dfs(i, adj, k, -1);

        return res;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        vector<int> res1 = findCount(edges1, k);
        vector<int> res2 = findCount(edges2, k - 1);

        int maxCnt = *max_element(begin(res2), end(res2));

        for (int i = 0; i < res1.size(); i++)
            res1[i] += maxCnt;

        return res1;
    }
};