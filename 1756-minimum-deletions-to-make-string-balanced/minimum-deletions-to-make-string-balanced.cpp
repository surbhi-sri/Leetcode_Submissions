class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> bn(n, 0);
        vector<int> an(n, 0);
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            bn[i] = b;
            if (s[i] == 'b')
                b++;
        }

        for (int i = n - 1; i >= 0; --i) {
            an[i] = a;
            if (s[i] == 'a')
                a++;
        }

        int cnt = n;
        for (int i = 0; i < n; i++) {
            cnt = min(cnt, an[i] + bn[i]);
        }
        return cnt;
    }
};