class Solution {
public:
    int merge_sort(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int cnt = 0;
        int i = low, j = mid + 1;

        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= high) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int k = low; k <= high; k++) {
            nums[k] = temp[k - low];
        }
        return cnt;
    }

    int count_pair(vector<int>& nums, int low, int mid, int high) {
        int cnt = 0;
        int i = low, j = mid + 1;
        while (i <= mid && j <= high) {
            long long int curr=nums[j];
            if (nums[i] > 2 * curr){
                cnt += (mid - i + 1);
            j++;
        }
        else i++;
    }
    return cnt;
}

    int merge(vector<int>& nums, int low, int high) {
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += merge(nums, low, mid);
    cnt += merge(nums, mid + 1, high);
    cnt += count_pair(nums, low, mid, high);
    merge_sort(nums, low, mid, high);
    return cnt;
}

int reversePairs(vector<int>& nums) {
    int n = nums.size();
    return merge(nums, 0, n - 1);
}
}
;