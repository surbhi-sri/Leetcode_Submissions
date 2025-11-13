class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();

        int one = 0, op = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                one++;

            if (i < n - 1 && s[i] == '0' && s[i + 1] == '1')
                op += one;
        }

        if (s[n - 1] == '0')
            op += one;

        return op;
    }
};