class Solution {
public:

int lessthank(int el, int m, int n){
    int sum=0;

    for(int i=1; i<=m; i++){
        sum+=min(el/i, n);
    }

    return sum;
}

    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m * n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (lessthank(mid, m, n) < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};