class Solution {
public:

 void merge(vector<vector<int>> &arr, int start, int mid, int end, vector<long long> &smaller, vector<long long> &larger){
        int n = mid-start+1;
        int m = end-mid;
        vector<vector<int>> arr1(n),arr2(m);
        for(int i=0;i<n;i++){
            arr1[i] = arr[start+i];
        }
        for(int i=0;i<m;i++){
            arr2[i] = arr[mid+1+i];
        }

        int i=0,j=0,k=start;
        while(i<n && j<m){
            if(arr1[i][0] > arr2[j][0]){
                smaller[arr2[j][1]] += i; // calculate no of smaller elements to left of curr element in array
                arr[k] = arr2[j];
                k++;
                j++;
            }else{
                larger[arr1[i][1]]+=(m-j); // calculate no of larger elements to right of curr element in array
                arr[k] = arr1[i];
                k++;
                i++;
            }
        }

        while(i<n){
            arr[k] = arr1[i];
            k++;
            i++;
        }

        while(j<m){
            smaller[arr2[j][1]] += n;
            arr[k] = arr2[j];
            k++;
            j++;
        }

    }

    void mergeSort(vector<vector<int>> &arr, int start, int end, vector<long long> &smaller, vector<long long> &larger){
        if(start>=end) return;
        int mid = (start+end)/2;
        mergeSort(arr,start,mid,smaller,larger);
        mergeSort(arr,mid+1,end,smaller,larger);
        merge(arr,start,mid,end,smaller,larger);
    }

    vector<vector<long long>> generateSmallerAndLarger(vector<int>& nums) {
        int n = nums.size();
        vector<long long> smaller(n,0);
        vector<long long> larger(n,0);
        vector<vector<int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        mergeSort(arr,0,n-1,smaller,larger);
        return {smaller,larger};
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        unordered_map<int,int> mp;
        int n = nums1.size();
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]] = i;
        }

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = mp[nums1[i]];
        }

        vector<vector<long long>> res = generateSmallerAndLarger(arr);
        vector<long long> smaller = res[0], larger = res[1];
        for(int i=0;i<n;i++){
            ans+=(smaller[i]*larger[i]);
        }

        return ans; 
    }
};