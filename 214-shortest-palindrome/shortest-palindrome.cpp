class Solution {
public:
    void Lps(string & str, vector<int>  & lps) {
        int len = 0;
        int i = 1;
        int n = str.size();

        while (i < n) {
            if (str[i] == str[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());

        int n = s.size();

        string temp = s + '-' + t;
        vector<int> lps(temp.size(), 0);

        Lps(temp, lps);

        int longest_lpsLength = lps[temp.length() - 1];

        return t.substr(0, n - longest_lpsLength) + s;
    }
};