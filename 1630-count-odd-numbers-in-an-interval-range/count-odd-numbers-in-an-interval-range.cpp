class Solution {
public:
    int countOdds(int low, int high) {
        if (low % 2)
            low--;
        if (high % 2)
            high++;

        return (high - low) / 2;
    }
};