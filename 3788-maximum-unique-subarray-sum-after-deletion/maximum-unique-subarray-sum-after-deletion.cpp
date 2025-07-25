class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int sum = 0;
        int max_ele=-100;

        for (int& num : nums) {
            max_ele= max(max_ele, num);
            if (num < 0)
                continue;
            if (st.count(num) == 0)
                sum += num;
            st.insert(num);
        }

        if(st.empty()) return max_ele;

        return sum;
    }
};