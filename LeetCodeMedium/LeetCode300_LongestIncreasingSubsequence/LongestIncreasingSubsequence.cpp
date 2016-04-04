#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        for (int i = 1; i < nums.size(); ++i)
        {
            int maxCount = -1;
            for (int j = 0; j<i; ++j)
            {
                if (nums[i]>nums[j] && maxCount <= count[j])
                {
                    maxCount = count[j];
                }

            }
            count[i] = maxCount + 1;


        }
        int maxLength = -1;
        for (int i = 0; i<count.size(); ++i)
        {
            if (count[i]>maxLength)
            {
                maxLength = count[i];
            }
        }
        return maxLength+1;

    }
};

int main()
{
    vector<int> nums{ 10, 9, 2, 5, 3, 7, 101, 18 };
    Solution sol;
    auto temp = sol.lengthOfLIS(nums);

    return 0;
}
