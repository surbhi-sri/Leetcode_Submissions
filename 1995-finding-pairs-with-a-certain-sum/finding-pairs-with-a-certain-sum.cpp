class FindSumPairs {
public:
   vector<int> num1, num2;
   unordered_map<int, int> mp1, mp2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        num1=nums1;
        num2=nums2;

       for(int &num: num1) mp1[num]++;
       for(int &num: num2) mp2[num]++;
    }
    
    void add(int index, int val) {
        mp2[num2[index]]--;
        if(mp2[num2[index]]==0) mp2.erase(num2[index]);

        num2[index]+=val;
         mp2[num2[index]]++;
    }
    
    int count(int tot) {
        int pair=0;

      for(auto &mp: mp1){
        int x=mp.first;
        int val1=mp.second;

        if(tot >x && mp2.find(tot-x)!=mp2.end()){
            int val2=mp2[tot-x];
            pair +=(val1*val2);
        }
      }

      return pair;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */