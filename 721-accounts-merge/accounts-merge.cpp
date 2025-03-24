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

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);

        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mp.find(mail) == mp.end())
                    mp[mail] = i;
                else
                    ds.unions(i, mp[mail]);
            }
        }

 vector<vector<string>> merge(n);
 
        for (auto it : mp) {
            string mail = it.first;
            int node = ds.find(it.second);
            merge[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (merge[i].size() == 0)
                continue;

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (auto it : merge[i])
                temp.push_back(it);

           sort(temp.begin() + 1, temp.end());

            ans.push_back(temp);
        }

        return ans;
    }
};