class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        int n = s.size();

        for (int i =  n / 2; i >=1; i--) {
             string str;
            str= s.substr(0,i);

            if (n % (i) == 0) {
                int times = n /i;

                string new_str = "";

                while (times--) {
                    new_str += str;
                }

                if (new_str == s)
                    return 1;
            }
        }
        return 0;
    }
};