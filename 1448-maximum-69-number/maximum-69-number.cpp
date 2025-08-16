class Solution {
public:
    int maximum69Number(int num) {
        int ans = 0;
        string s = to_string(num);
        bool k = 1;
        for (char c : s) {
            if (c - '0' == 6 && k) {
                k = 0;
                ans = ans * 10 + 9;
            } else
                ans = ans * 10 + (c - '0');
        }

        return ans;
    }
};