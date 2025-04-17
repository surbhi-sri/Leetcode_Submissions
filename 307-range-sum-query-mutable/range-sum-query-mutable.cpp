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
        buildTree(2 * i + 2, mid + 1, r, nums);

        segementTree[i] = segementTree[2 * i + 1] + segementTree[2 * i + 2];
    }

    int sum(int i, int l, int r, int left, int right) {
        if (right < l || left > r)
            return 0;

        if (l >= left && r <= right)
            return segementTree[i];

        int mid = l + (r - l) / 2;

        return sum(2 * i + 1, l, mid, left, right) +
               sum(2 * i + 2, mid + 1, r, left, right);
    }

    void change(int i, int l, int r, int index, int val) {
        if (l == r) {
            segementTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid)
            change(2 * i + 1, l, mid, index, val);
        else
            change(2 * i + 2, mid + 1, r, index, val);

        segementTree[i] = segementTree[2 * i + 1] + segementTree[2 * i + 2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segementTree.resize(4 * n);

        buildTree(0, 0, n - 1, nums);
    }

    void update(int index, int val) { change(0, 0, n - 1, index, val); }

    int sumRange(int left, int right) { return sum(0, 0, n - 1, left, right); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */