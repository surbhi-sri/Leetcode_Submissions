class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] == target)
                return 1;
        return 0;
        // int left = 0, right = n - 1;
        // while (left <= right) {
        //     int mid = left + (right - left) / 2;
        //     if (nums[mid] == target)
        //         return 1;
        //     else if (nums[left] <= nums[right]) {
        //         if (nums[left]<=target && target<nums[mid]) right=mid-1;
        //         else left=mid+1;
        //     } else {
        //          if (nums[mid]<target && target<=nums[right]) left=mid+1;
        //         else right=mid-1;
        //     }
        // }
        // return 0;
    }
};