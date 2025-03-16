class Solution {
public:
    int mod = 1e9 + 7;

    vector<int> NSE(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        if (n == 0)
            return 0;

        vector<int> nse = NSE(arr, n);

        stack<int> st;

        long long sum = 0;

        // using previouse smaller than equal to element

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            int psee = st.empty() ? -1 : st.top();

            int left = i - psee;
            int right = nse[i] - i;

            sum = (sum + (1LL * left * right * arr[i]) % mod) % mod;

            st.push(i);
        }

        return sum;
    }
};