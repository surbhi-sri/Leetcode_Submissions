class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0, mn = 10000;

        for (int i = 1; i < n; i++) {
            mn = min(mn, prices[i - 1]);
            profit = max(profit, (prices[i] - mn));
        }

        return profit;
    }
};