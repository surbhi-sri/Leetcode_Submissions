class Solution {
public:
    long long solve(int ind, int n, vector<vector<int>>& questions, vector<long long>& dp) {
        if (ind >= n)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        long long notTake = solve(ind + 1, n, questions, dp);

        long long take = questions[ind][0] +
                   solve(ind + questions[ind][1] + 1, n, questions, dp);

        return dp[ind] = max(take, notTake);
    }

    long long mostPoints(vector<vector<int>>& questions) {

        int n = questions.size();

        vector<long long> dp(n + 1, -1);

        return solve(0, n, questions, dp);
    }
};