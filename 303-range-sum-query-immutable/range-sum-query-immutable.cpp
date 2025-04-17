class NumArray {
public:
    int n;
    vector<int> segementTree;

    void buildTree(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            segementTree[i] = nums[r];
            return;
        }

        int mid = l + (r - l) / 2;

        buildTree(2 * i + 1, l, mid, nums);
        buildTree(2 * i + 2, mid +1, r, nums);

        segementTree[i] = segementTree[2 * i + 1] + segementTree[2 * i + 2];
    }

    int sum(int i, int l, int r, int left, int right) {
        if (right < l || left > r)
            return 0;

        if (l >= left && r <= right)
            return segementTree[i];

        int mid = l + (r - l) / 2;

        return sum(2 * i + 1, l, mid, left, right) +
               sum(2 * i + 2, mid +1, r, left, right);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segementTree.resize(4 * n);

        buildTree(0, 0, n - 1, nums);
    }

    int sumRange(int left, int right) { return sum(0, 0, n - 1, left, right); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */