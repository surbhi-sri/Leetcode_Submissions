class Solution {
public:
    int myAtoi(string s) {
        int n = 1;
        int i = 0;
        while (i < s.size() && s[i] == ' ')
            i++;
        if (i < s.size() && s[i] == '-') {
            i++;
            n = 0 - n;
        } else if (i < s.size() && s[i] == '+')
            i++;

        long long int num = 0;

        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {

            num = (num * 10) + (s[i] - '0');
            if (num > INT_MAX) {
                if (n > 0)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            i++;
        }

        if (n < 0)
            return (0 - num);
        else
            return num;
    }
};