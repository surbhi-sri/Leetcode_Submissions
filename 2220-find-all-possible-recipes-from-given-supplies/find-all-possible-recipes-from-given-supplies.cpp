class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        unordered_set<string> st(supplies.begin(), supplies.end());
        vector<string> ans;

        int n = recipes.size();

        unordered_map<string, vector<int>> mp;
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (string& str : ingredients[i]) {
                if (!st.count(str)) {
                    mp[str].push_back(i);
                    indegree[i]++;
                }
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(recipes[node]);

            for (int& it : mp[recipes[node]]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return ans;
    }
};