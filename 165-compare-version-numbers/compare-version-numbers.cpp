class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1);
        stringstream ss2(version2);

        vector<int> vec;
        string num;

        while (getline(ss1, num, '.')) {
            vec.push_back(stoi(num));
        }
        int i = 0, n = vec.size();
         string num2;

        while (getline(ss2, num2, '.')) {
            int val = stoi(num2);
            if (i >= n && val > 0)
                return -1;
            else if (i<n && vec[i] > val)
                return 1;
            else if (i<n && vec[i] < val)
                return -1;
            else
                i++;
        }

        while(i<n){
            if(vec[i]>0) return 1;
            i++;
        }

        return 0;
    }
};