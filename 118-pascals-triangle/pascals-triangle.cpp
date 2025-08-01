class Solution {
public:
    vector<int> pascle(int n) {
        if (n == 1)
            return {1};
        if (n == 2)
            return {1, 1};

        n--;
        vector<int> temp;

        for (int i = 0; i <= n; i++) {
            int res = 1;
            for (int j = 0; j < i; j++) {
                res *= (n - j);
                res /= (j + 1);
            }
            temp.push_back(res);
        }
        return temp;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 1; i <= numRows; i++) {
            vector<int> temp = pascle(i);
            ans.push_back(temp);
        }

        return ans;
    }
};