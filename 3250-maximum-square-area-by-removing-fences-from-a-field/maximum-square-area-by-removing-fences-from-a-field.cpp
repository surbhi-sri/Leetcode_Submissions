class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {
        int nh = hFences.size();
        int nv = vFences.size();

        unordered_set<int> st;

        st.insert(m - 1);

        for (int i = 0; i < nh; i++) {
            st.insert(hFences[i] - 1);
            st.insert(m - hFences[i]);

            for (int j = i + 1; j < nh; j++) {
                st.insert(abs(hFences[j] - hFences[i]));
            }
        }

        long long side = 0;

        for (int i = 0; i < nv; i++) {
            if (st.count(vFences[i] - 1) > 0)
                side = max(side, (long long)(vFences[i] - 1));

            if (st.count(n - vFences[i]) > 0)
                side = max(side, (long long)(n - vFences[i]));

            for (int j = i + 1; j < nv; j++) {
                if (st.count(abs(vFences[j] - vFences[i])) > 0)
                    side = max(side, (long long)abs(vFences[j] - vFences[i]));
            }
        }

        if (st.count(n - 1) > 0)
            side = max(side, (long long)(n - 1));

        const long long MOD = 1e9 + 7;

        return side == 0 ? -1 : (side * side) % MOD;
    }
};