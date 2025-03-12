class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int n = nums.size();

        int neg = -1, pos = n;

        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left / 2);
            if (nums[mid] < 0) {
                neg = mid;
                left = mid + 1;
            }
             else if (nums[mid] > 0) {
                pos = mid;
                right = mid - 1;
            }
             else {
                int temp_left = mid - 1, temp_right = mid + 1;

                while (temp_left >= left && nums[temp_left] == 0)
                    temp_left--;

                while (temp_right <= right && nums[temp_right] == 0)
                    temp_right++;

                neg = temp_left;
                pos = temp_right;

                break;
            }
        }

        neg += 1;
        pos = n - pos;

        return max(neg, pos);
    }
};