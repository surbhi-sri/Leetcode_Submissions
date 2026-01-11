class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        stack<int> st;
        int n = height.size();

        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : height[i];
            while (!st.empty() && height[st.top()] > h) {
                int l = height[st.top()];
                // int b=i - st.top();
                st.pop();

                int b = st.empty() ? i : i - st.top() - 1;
                area = max(area, l * b);
            }
            st.push(i);
        }

        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int area = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rect(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    rect[j] += (matrix[i][j] - '0');
                else
                    rect[j] = 0;
            }

            area = max(area, maxArea(rect));
        }

        return area;
    }
};