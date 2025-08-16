class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1 || n == 1)
            return nums;

        deque<int> pq;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!pq.empty() && pq.front() <= i - k)
                pq.pop_front();
            while (!pq.empty() && nums[pq.back()] <= nums[i])
                pq.pop_back();
            pq.push_back(i);
            if (i >= k - 1)
                ans.push_back(nums[pq.front()]);
        }
        return ans;
    }
};