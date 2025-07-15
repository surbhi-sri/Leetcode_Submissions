class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if (n < 3)
            return 0;
        bool v = 0, c = 0;

        for (char ch : word) {
            if (ch >= '0' && ch <= '9')
                continue;
            else if (ch >= 'a' && ch <= 'z') {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                    ch == 'u')
                    v = 1;
                else
                    c = 1;
                continue;
            } else if (ch >= 'A' && ch <= 'Z') {
                if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' ||
                    ch == 'U')
                    v = 1;
                else
                    c = 1;
                continue;
            } else
                return 0;
        }

        return (v & c);
    }
};