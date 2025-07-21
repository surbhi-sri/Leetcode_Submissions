class Solution {
public:
    string makeFancyString(string s) {
        string str;
        int n = s.size();

        if (n < 3)
            return s;

        str += s[0];
        str += s[1];

        for (int i = 2; i < n; i++) {
            if (s[i] == s[i - 2] && s[i]==s[i-1])
                continue;
            else
                str += s[i];
        }

        return str;
    }
};