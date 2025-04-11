class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;

        for (int num = low; num <= high; num++) {
            if (num >= 11 && num <= 99 && num % 11 == 0)
                cnt++;
            else if (num >= 1001 && num <= 9999) {
                int first = num / 1000;
                int second = (num / 100) % 10;
                int third = (num / 10) % 10;
                int fourth = num % 10;

                if (first + second == third + fourth) cnt++;
            }
        }

        return cnt;
    }
};