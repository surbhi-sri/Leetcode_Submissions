class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs.size();
        if (n == 1)
            return strs[0];
        for (int j = 0; j < 200; j++) {
            for (int i = 0; i < n - 1; i++) {
                if (j > strs[i].size() || strs[i][j] != strs[i + 1][j])
                   return strs[0].substr(0, j);
            }
        }
        return strs[0];
    }
};