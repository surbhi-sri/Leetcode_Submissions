class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c=1;
        int n = digits.size();
       
        for (int i = n - 1; i >= 0; i--) {
            if (c) {
                c = (digits[i] + 1) / 10;
                digits[i] = (digits[i] + 1) % 10;
            } else
                break;
        }

        if (c){
            digits.push_back(0);
            digits[0]=1;
        }

        return digits;
    }
};