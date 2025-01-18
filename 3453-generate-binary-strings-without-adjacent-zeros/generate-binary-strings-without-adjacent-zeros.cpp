class Solution {
public:
    void solve(string& s, vector<string>& ans, int n) {
        if (s.size() == n) {
            ans.push_back(s);
            return;
        }
        if (s.empty() || (!s.empty() && s[s.size() - 1] != '0')) {
            s.push_back('0');
            solve(s, ans, n);
            s.pop_back();
        }
        s.push_back('1');
        solve(s, ans, n);
        s.pop_back();
    }

    vector<string> validStrings(int n) {
        string s;
        vector<string> ans;
        solve(s, ans, n);
        return ans;
    }
};