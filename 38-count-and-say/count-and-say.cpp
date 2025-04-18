class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";

        string str = countAndSay(n - 1);

        int len = str.size();
        string res;

        int i = 0, j = 1;
        char ch = str[0];

        while (1) {
            if (j < len) {
                if (ch == str[j])
                    j++;
                else {
                    char num = '0' + (j - i);
                    res.push_back(num);
                    res.push_back(ch);

                    ch = str[j];
                    i = j;
                }
            } else {
                char num = '0' + (j - i);
                res.push_back(num);
                res.push_back(ch);

                break;
            }
        }

        return res;
    }
};