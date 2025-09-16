class Solution {
public:
    int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        ans.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            int num1 = ans.back();
            int num2 = nums[i];
            int hcf = gcd(num1, num2);
            while (hcf > 1) {
                ans.pop_back();
                int lcm = (num1 / hcf) * num2;
                num2 = lcm;
                if (ans.empty())
                    break;
                num1 = ans.back();
                hcf = gcd(num1, num2);
            }
            ans.push_back(num2);
        }
        return ans;
    }
};