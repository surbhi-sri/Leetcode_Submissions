class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills[0] != 5)
            return 0;
        int n = bills.size();
        int c5 = 1;
        int c10 = 0;
        int c20 = 0;
        for (int i = 1; i < n; i++) {
            int change = bills[i] - 5;
            if (bills[i] == 5)
                c5++;
            else if (bills[i] == 10)
                c10++;
            else
                c20++;
            if (change == 0)
                continue;
            else if (change == 5) {
                if (c5 > 0)
                    c5--;
                else
                    return 0;
            } else {
                if (c5 > 0 && c10 > 0) {
                    c5--;
                    c10--;
                } else if (c5 > 2)
                    c5 -= 3;
                else
                    return 0;
            }
        }
        return 1;
    }
};