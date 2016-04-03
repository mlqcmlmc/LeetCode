#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int m = l;
        while (nums[l]>nums[r])
        {
            if (r - l == 1)
            {
                m = r;
                break;
            }
            m = (l + r) / 2;
            if (nums[m]< nums[r])
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        return nums[m];

    }

};

int main()
{
    vector<int> nums{ 3,1,2 };
    Solution sol;
    auto temp = sol.findMin(nums);

    return 0;
}
