class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[nums[i]]++;

        queue<pair<int, int>> q;

        for (auto& m : mp)
            q.push({m.first, m.second});

        int len = 0;
        int ele1 = q.front().first;
        int cnt1 = q.front().second;
        q.pop();

        while (!q.empty()) {
            int ele2 = q.front().first;
            int cnt2 = q.front().second;
            q.pop();
            if (ele1 + 1 == ele2) {
                len = max(len, cnt1 + cnt2);
            }
            ele1 = ele2;
            cnt1 = cnt2;
        }
        return len;
    }
};