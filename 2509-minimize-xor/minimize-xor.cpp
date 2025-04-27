class Solution {
public:
    int count_bits(int num) {
        int cnt = 0;

        while (num) {
            if (num & 1)
                cnt++;
            num = num >> 1;
        }
        return cnt;
    }

    int minimizeXor(int num1, int num2) {
        int setBits1 = count_bits(num1);
        int setBits2 = count_bits(num2);

        if (setBits1 == setBits2)
            return num1;

        int bit_diff = abs(setBits1 - setBits2);
        int x = num1;

        if (setBits1 > setBits2) {
            for (int i = 0; i < 32; i++) {
                if (((x >> i) & 1) > 0) {
                    x = x ^ (1 << i);

                    bit_diff--;
                    if (bit_diff == 0)
                        break;
                }
            }
        } else {
            for (int i = 0; i < 32; i++) {
                if (((x >> i) & 1) ==0) {
                    x = x ^ (1 << i);

                    bit_diff--;
                    if (bit_diff == 0)
                        break;
                }
            }
        }

        return x;
    }
};