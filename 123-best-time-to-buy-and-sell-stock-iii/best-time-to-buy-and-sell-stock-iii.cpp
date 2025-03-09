class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> ahead(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int cap = 1; cap <= 2; cap++) {

                    int profit = 0;

                    if (buy)
                        profit =
                            max(-prices[ind] + ahead[0][cap], ahead[1][cap]);
                    else
                        profit =
                            max(prices[ind] + ahead[1][cap - 1], ahead[0][cap]);

                    curr[buy][cap] = profit;
                }
            }
            ahead = curr;
        }

        return ahead[1][2];
    }
};