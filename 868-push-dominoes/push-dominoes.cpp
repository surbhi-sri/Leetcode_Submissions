class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();

        vector<int> left(n, n);
        int l = n, r = -1;

        for (int i = n - 1; i >= 0; i--) {

            if (l == n && dominoes[i] == '.')
                continue;

            if (dominoes[i] == 'L')
                l = min(l, i);

            left[i] = l;

            if (dominoes[i] == 'R')
                l = n;
        }
        string ans;

        for (int i = 0; i < n; i++)
            cout << left[i] << " ";

        cout << endl;

        for (int i = 0; i < n; i++) {

            if (r == -1 && dominoes[i] != 'R') {
                if (left[i] < n)
                    ans += 'L';
                else
                    ans += '.';
                continue;
            }

            if (left[i] == n && r != -1) {
                ans += 'R';
                continue;
            }

            if (dominoes[i] == 'R')
                r = max(r, i);

            char push;

            if ((i - r) < left[i] - i)
                push = 'R';
            else if ((i - r) > left[i] - i)
                push = 'L';
            else
                push = '.';

            ans += push;

            if (dominoes[i] == 'L')
                r = -1;
        }

        return ans;
    }
};