class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> bn(n, 0);
        int a = 0, b = 0;

        for (int i = 0; i < n; i++) {
            bn[i] = b;
            if (s[i] == 'b')
                b++;
        }

        int cnt = n;

        for (int i = n - 1; i >= 0; --i) {
            cnt = min(cnt, a + bn[i]);
            if (s[i] == 'a')
                a++;
        }

        return cnt;
    }
};