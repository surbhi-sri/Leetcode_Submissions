class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n <= 1)
            return n;
        vector<int> v;
        v.push_back(nums[0]);
        for (int i = 1; i < n ; i++) {
            while (i < n - 1 && nums[i] == nums[i - 1])
                i++;
            v.push_back(nums[i]);
        }
        n = v.size();
        int len = 1;
        int i = 0, j = 1;
        while (j < n) {
            while (j < n && v[j] - 1 == v[j - 1])
                j++;
            len = max(len, j - i);
            i = j;
            j++;
        }
        return len;
    }
};