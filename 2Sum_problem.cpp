class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int i, j;
        vector<int> ss;

        for (i = 0; i < nums.size(); i++)
            for (j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target)
                {
                    ss.push_back(i);
                    ss.push_back(j);
                }
        return ss;
    }
};