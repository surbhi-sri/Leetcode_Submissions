class Solution {
public:
    void solve(vector<string>& ans, string path, long long res, long long pre,
               long long ind, string num, int target) {

        if (ind == num.size()) {
            if (res == target)
                ans.push_back(path);
            return;
        }

        string temp = "";
        long long curr = 0;

        for (int i = ind; i < num.size(); i++) {
            if (i > ind && num[ind] == '0')
                break;
            temp += num[i];
            curr = curr * 10 + (num[i] - '0');
            if (ind == 0) {
                solve(ans, path + temp, curr, curr, i + 1, num, target);
            } else {
                solve(ans, path + "+" + temp, res + curr, curr, i + 1, num,
                      target);
                solve(ans, path + "-" + temp, res - curr, -curr, i + 1, num,
                      target);
                solve(ans, path + "*" + temp, res - pre + (pre * curr),
                      pre * curr, i + 1, num, target);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(ans, "", 0, 0, 0, num, target);
        return ans;
    }
};