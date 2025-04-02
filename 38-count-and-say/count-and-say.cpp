class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";

        string s = countAndSay(n - 1);
        if (s == "1")
            return "11";

        int len = s.size();
        int i = 0, j = 1;
        char ch = s[0];

        string str;

        while (1) {

            if (j < len) {

                if (ch == s[j]) {
                    j++;
                } else {
                    char num = '0' + (j - i);
                    str.push_back(num);
                    str.push_back(ch);

                    ch = s[j];
                    i = j;
                }

            } else {
                char num = '0' + (j - i);
                str.push_back(num);
                str.push_back(ch);

                break;
            }
        }

        return str;
    }
};