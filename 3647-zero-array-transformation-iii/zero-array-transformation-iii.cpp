class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int qn = queries.size();

        sort(queries.begin(), queries.end());

        priority_queue<int> mp; // to store farthest ending
        priority_queue<int, vector<int>, greater<int>>  past; // to store past ending

        int j = 0;        // point to queries
        int used_cnt = 0; // how many queries i have used

        for (int i = 0; i < n; i++) {
            while (j<qn && queries[j][0] == i) {
                mp.push(queries[j][1]);
                j++;
            }

            nums[i] -= past.size();

            while (nums[i] > 0 && !mp.empty() && mp.top() >= i) {
                int end = mp.top();
                mp.pop();
                past.push(end);
                used_cnt++;
                nums[i]--;
            }

            if (nums[i] > 0)
                return -1;

            while (!past.empty() && past.top() <= i)
                past.pop();
        }

        return qn - used_cnt;
    }
};