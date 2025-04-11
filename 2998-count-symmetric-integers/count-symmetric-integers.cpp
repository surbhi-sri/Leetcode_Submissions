class Solution {
public:
    bool isSym(int num) {
        string str = to_string(num);
        int n = str.size();

        if (n % 2 != 0)
            return 0;

        int l = 0, r = n - 1;
        int sum_l = 0, sum_r = 0;
        while (l < r) {
            sum_l += (str[l] - '0');
            sum_r += (str[r] - '0');
            l++;
            r--;
        }

        return sum_l == sum_r;
    }

    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;

        for (int i = low; i <= high; i++) {
            if (isSym(i))
                cnt++;
        }

        return cnt;
    }
};