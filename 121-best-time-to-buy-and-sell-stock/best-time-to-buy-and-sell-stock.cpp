class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mx_profit = 0;
        int mn = prices[0];

        for (int i = 0; i < n; i++) {
            mx_profit = max(mx_profit, prices[i] - mn);
            mn = min(mn, prices[i]);
        }

        return mx_profit;
    }
};