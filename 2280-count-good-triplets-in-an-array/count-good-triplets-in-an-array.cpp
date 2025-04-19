class Solution {
public:
    void update(int i, int l, int r, vector<long long>& st, int idx) {
        if (l == r) {
            st[i] = 1;
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
            update(2 * i + 1, l, mid, st, idx);
        else
            update(2 * i + 2, mid + 1, r, st, idx);

        st[i] = st[2 * i + 1] + st[2 * i + 2];
    }

    long long querySt(int qs, int qe, int i, int l, int r,
                      vector<long long>& st) {
        if (l > qe || r < qs)
            return 0;

        if (qs <= l && r <= qe)
            return st[i];

        int mid = l + (r - l) / 2;

        return querySt(qs, qe, 2 * i + 1, l, mid, st) +
               querySt(qs, qe, 2 * i + 2, mid + 1, r, st);
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        int n = nums1.size();

        for (int i = 0; i < n; i++)
            mp[nums2[i]] = i;

        long long cnt = 0;

        vector<long long> st(4 * n);

        update(0, 0, n - 1, st, mp[nums1[0]]);

        for (int i = 1; i < n; i++) {

            int idx = mp[nums1[i]];

            long long leftCommCnt = querySt(0, idx, 0, 0, n - 1, st);
            long long leftNotCommCnt = i - leftCommCnt;

            long long eleAfterIdxNum = n - 1 - idx;
            long long rightCommCnt = eleAfterIdxNum - leftNotCommCnt;

            cnt += (leftCommCnt * rightCommCnt);
            update(0, 0, n - 1, st, idx);
        }

        return cnt;
    }
};