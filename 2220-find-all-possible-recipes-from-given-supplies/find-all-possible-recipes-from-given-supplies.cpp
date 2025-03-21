class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        unordered_set<string> st(supplies.begin(), supplies.end());
        vector<string> ans;

        int n = recipes.size();

        int added = 1;
        
        while (added) {
            added = 0;
            for (int i = 0; i < n; i++) {
                if (st.count(recipes[i]))
                    continue;
                int flag = 1;
                for (int j = 0; j < ingredients[i].size(); j++) {
                    if (st.find(ingredients[i][j]) == st.end()) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    ans.push_back(recipes[i]);
                    st.insert(recipes[i]);
                    added = 1;
                }
            }
        }
        return ans;
    }
};