class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int filled = numBottles;
        int not_filled = 0;
        int cnt = 0;
        while (numBottles >= numExchange) {
            cnt += filled;

            filled = (numBottles / numExchange);
            not_filled = (numBottles % numExchange);

            numBottles=(filled+not_filled);
        }

        return cnt + filled;
    }
};