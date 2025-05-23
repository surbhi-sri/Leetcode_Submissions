class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        ll sum = 0;
        int cnt = 0;
        int min_nuksan = INT_MAX;

        for (ll num : nums) {
            if ((num ^ k) > num) {
                sum += (num ^ k);
                cnt++;
            } else
                sum += num;

            min_nuksan = min((ll)min_nuksan, abs(num - (num ^ k)));
        }

        if (cnt % 2 == 0)
            return sum;

        return (sum - min_nuksan); 
    }
};