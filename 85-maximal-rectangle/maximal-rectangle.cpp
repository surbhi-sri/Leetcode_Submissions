class Solution {
public:
    int area(vector<int>& height, int n) {

        int maxArea = 0;
        stack<int> st;

        for (int i = 0; i <= n; i++) {

            while (!st.empty() && (i == n || height[st.top()] > height[i])) {

                int h = height[st.top()];
                st.pop();

                int w = st.empty() ? i : i - st.top() - 1;

                maxArea = max(maxArea, h * w);
            }

            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            maxArea = max(maxArea, area(height, m));
        }

        return maxArea;
    }
};