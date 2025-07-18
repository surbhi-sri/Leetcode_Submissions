class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<long long> left;
        priority_queue<long long, vector<long long>, greater<long long>> right;
        int n = nums.size();
        int parts = n / 3;
        vector<long long> leftsum(n, 100000);
        vector<long long> rightsum(n, 1);

        long long sum = 0;
        for (int i = 0; i < n - parts; i++) {
            sum += nums[i];
            left.push(nums[i]);
            if (left.size() > parts) {
                sum -= left.top();
                left.pop();
            }
            leftsum[i] = sum;
        }

        sum = 0;
        for (int i = n - 1 ;i >= parts; i--) {
            sum += nums[i];
            right.push(nums[i]);
            if (right.size() > parts) {
                sum -= right.top();
                right.pop();
            }
            rightsum[i] = sum;
        }

        long long mind = LONG_MAX;

        for (int i = parts - 1; i < n - parts; i++) {
            mind = min(mind, leftsum[i] - rightsum[i + 1]);
        }

        return mind;
    }
};