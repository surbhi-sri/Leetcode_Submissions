class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> vec;
        stringstream s1(version1);
        stringstream s2(version2);

        string num;

        while (getline(s1, num, '.')) {
            vec.push_back(stoi(num));
        }

        int i = 0, n = vec.size();

        while (getline(s2, num, '.')) {
            int val = stoi(num);
            if ((i >= n && val > 0) || (i < n && val > vec[i]))
                return -1;
            else if (i < n && val < vec[i])
                return 1;
            else
                i++;
        }

        while (i < n) {
            if (vec[i] > 0)
                return 1;
            i++;
        }

        return 0;
    }
};