class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0, n = details.size();
        for (int i = 0; i < n; i++) {
            string s = details[i];
            if (s[11] - '0' > 6 || (s[11] - '0' == 6 && s[12] - '0' > 0))
                cnt++;
        }
        return cnt;
    }
};