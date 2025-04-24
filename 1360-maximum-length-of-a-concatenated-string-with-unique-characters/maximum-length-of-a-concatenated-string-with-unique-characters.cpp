class Solution {
public:
    void solve(int idx, int temp, int& res, vector<int>& uniquecharstring) {

        res = max(res, __builtin_popcount(temp));

        for (int i = idx; i < uniquecharstring.size(); i++) {
            if ((temp & uniquecharstring[i] )== 0)
                solve(i + 1, temp | uniquecharstring[i], res, uniquecharstring);
        }
    }

    int maxLength(vector<string>& arr) {
        vector<int> uniquecharstring;

        for (string& s : arr) {
            unordered_set<char> st(begin(s), end(s));

            if (st.size() != s.size())
                continue;

            int val = 0;
            for (char& ch : s) {
                val = (val | (1 << (ch - 'a')));
            }

            uniquecharstring.push_back(val);
        }

        int res = 0;

        solve(0, 0, res, uniquecharstring);

        return res;
    }
};