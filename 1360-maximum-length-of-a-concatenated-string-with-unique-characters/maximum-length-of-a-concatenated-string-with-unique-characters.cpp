class Solution {
public:

    bool hasduplicate(string &a, string &b){
        unordered_set<char> st;
        for(char ch: a){
            if(st.count(ch)>0) return 1;
            st.insert(ch);
        }

        for(char ch: b){
            if(st.count(ch)>0) return 1;
            st.insert(ch);
        }

        return 0;
    }

    int solve(int i, string temp, vector<string>& arr, int n) {
        if (i >= n)
            return temp.size();

        int include = 0;
        int exclude = 0;

        if (!hasduplicate(temp, arr[i])) {
            include = solve(i + 1, temp + arr[i], arr, n);
        }

        exclude = solve(i + 1, temp, arr, n);

        return max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        string temp = "";
        int n = arr.size();

        return solve(0, temp, arr, n);
    }
};