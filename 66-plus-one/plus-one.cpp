class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c;
        int n = digits.size();
        c = (digits[n - 1] + 1) / 10;
        digits[n - 1] =
            (digits[n - 1] == 9) ? (n - 1 == 0 ? 1 : 0) : digits[n - 1] + 1;

        for (int i = n - 2; i >= 0; i--) {
            if (c) {
                c = (digits[i] + 1) / 10;
                digits[i] = (digits[i] == 9) ? (i == 0 ? 1 : 0) : digits[i] + 1;
            } else
                break;
        }

        if (c)
            digits.push_back(0);

        return digits;
    }
};