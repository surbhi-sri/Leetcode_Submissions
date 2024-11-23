class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<>());
        int mx_cnt=1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int ele = nums[i];
            int kn = k;
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                while (j<n && ele == nums[j]) {
                    i++;
                    j++;
                    count++;
                }
                if(j == n) break;
                if(j<n) kn -= (ele - nums[j]);
                if (kn < 0)
                    break;
                count++;
            }
            if(count > mx_cnt) mx_cnt=count;
        }
        return mx_cnt;
    }
};