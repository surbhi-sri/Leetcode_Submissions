class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int i = l + 1, j = r;
        int p = nums[l];

        while (i <= j) {
            if (nums[i] < p && nums[j] > p) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if (nums[i] >= p)
                i++;
            if (nums[j] <= p)
                j--;
        }

        swap(nums[l], nums[j]);

        return j;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0, r = n - 1;
        int pivot = 0;

        while (l <= r) {
            pivot = partition(nums, l, r);
            if (pivot == k - 1)
                break;
            else if (pivot < k - 1)
                l = pivot + 1;
            else
                r = pivot - 1;
        }

        return nums[pivot];
    }
};