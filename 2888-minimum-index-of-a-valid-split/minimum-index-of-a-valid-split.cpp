class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dominant = -1;
        int cnt = 0;

        for (int num : nums) {
            if (cnt == 0) {
                dominant = num;
                cnt = 1;
            } else if (dominant == num)
                cnt++;
            else
                cnt--;
        }

        cnt = 0;

        vector<int> count;

        for (int num : nums) {
            if (num == dominant)
                cnt++;
            cout << cnt << " ";
            count.push_back(cnt);
        }

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (count[i] > (i + 1) / 2 && (cnt - count[i]) > (n - i - 1)/2)
                return i;
        }

        return -1;
    }
};