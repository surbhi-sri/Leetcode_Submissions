class Solution {
public:
    void solve(string& s, vector<string>& ans, int n, int open, int close) {
        if (close > open || open > n || close > n)
            return;
        if (s.size() == 2 * n) {
            if (open ==close)
                ans.push_back(s);
            return;
        }

        s.push_back('(');
        solve(s, ans, n, open + 1, close);
        s.pop_back();
        s.push_back(')');
        solve(s, ans, n, open, close + 1);
        s.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        solve(s, ans, n, 0, 0);
        return ans;
    }
};