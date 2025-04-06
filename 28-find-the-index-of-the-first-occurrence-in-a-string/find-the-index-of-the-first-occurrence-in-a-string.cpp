class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i < n - m + 1; i++) {
            if (haystack[i] == needle[0]) {
                int j1 = i;
                int j2 = 0;
                while (j1 < n && j2 < m && haystack[j1] == needle[j2]) {
                    j1++;
                    j2++;
                }
                if (j2 == m)
                    return i;
            }
        }

        return -1;
    }
};