class Solution {
public:
    int merge(int left, int mid, int right, vector<int>& nums) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> l1(n1);
        vector<int> l2(n2);

        for (int i = 0; i < n1; i++)
            l1[i] = nums[i + left];
        for (int i = 0; i < n2; i++)
            l2[i] = nums[i + mid + 1];

        int cnt = 0;
        int k = left;
        int i = 0, j = 0;

        while (i < n1 && j < n2) {
            long long int curr = l2[j];
            if (l1[i] > (2 * curr)) {
                cnt += (n1 - i);
                j++;
            } else
                i++;
        }

        i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (l1[i] > l2[j])
                nums[k] = l2[j++];
            else
                nums[k] = l1[i++];

            k++;
        }

        while (i < n1) {
            nums[k] = l1[i];
            i++;
            k++;
        }

        while (j < n2) {
            nums[k] = l2[j];
            j++;
            k++;
        }

        return cnt;
    }

    int mergesort(int left, int right, vector<int>& nums) {
        if (left >= right)
            return 0;
        int cnt = 0;
        int mid = left + (right - left) / 2;
        cnt += mergesort(left, mid, nums);
        cnt += mergesort(mid + 1, right, nums);
        cnt += merge(left, mid, right, nums);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort(0, nums.size() - 1, nums);
    }
};