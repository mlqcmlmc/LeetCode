#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /***********一定要先取余**************/
        k = k%nums.size();

        int temp;
        for (int i = 0; i < nums.size() / 2; ++i)
        {
            temp = nums[i];
            nums[i] = nums[nums.size() - 1 - i];
            nums[nums.size() - 1 - i] = temp;
        }
        for (int i = 0; i < k / 2; ++i)
        {
            temp = nums[i];
            nums[i] = nums[k - 1 - i];
            nums[k - 1 - i] = temp;
        }
        for (int i = k; i < (nums.size() + k) / 2; ++i)
        {
            temp = nums[i];
            nums[i] = nums[nums.size() + k - 1 - i];
            nums[nums.size() + k - 1 - i] = temp;
        }



    }
};

int main()
{
    vector<int> nums{ 1, 2, 3, 4, 5, 6, 7 };
    Solution sol;
    sol.rotate(nums,3);

    return 0;
}