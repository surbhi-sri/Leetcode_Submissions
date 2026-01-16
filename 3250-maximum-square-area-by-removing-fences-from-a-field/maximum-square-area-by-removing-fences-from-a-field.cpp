class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {
        unordered_set<int> st;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        int nh = hFences.size();
        int nv = vFences.size();

        for (int i = 0; i < nh; i++) {
            for (int j = i + 1; j < nh; j++) {
                st.insert(abs(hFences[j] - hFences[i]));
            }
        }

        long long side = 0;

        for (int i = 0; i < nv; i++) {

            for (int j = i + 1; j < nv; j++) {
                long long diff = abs(vFences[j] - vFences[i]);
                if (st.count(diff) > 0)
                    side = max(side, diff);
            }
        }

        const long long MOD = 1e9 + 7;

        return side == 0 ? -1 : (side * side) % MOD;
    }
};