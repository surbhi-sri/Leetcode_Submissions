class Solution {
public:
    int myAtoi(string s) {
        string temp = "";
        int n = 1;
        int i = 0;
        while (i < s.size() && s[i] == ' ')
            i++;
        if (i < s.size() && s[i] == '-') {
            i++;
            n = 0 - n;
        } else if (i < s.size() && s[i] == '+')
            i++;

        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            temp += s[i];
            i++;
        }

        long long int num = 0;
        for (int i = 0; i < temp.size(); i++) {
            num = (num * 10) + (temp[i] - '0');
            if (num > INT_MAX) {
                if (n > 0)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
        }

        if (n < 0)
            return (0 - num);
        else
            return num;
    }
};