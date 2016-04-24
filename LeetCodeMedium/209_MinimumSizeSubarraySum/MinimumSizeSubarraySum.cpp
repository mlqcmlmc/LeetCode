#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty() || s <= 0)
        {
            return 0;
        }
        int start = 0, end = 0, minLen = nums.size() + 1;
        int sum = 0;
        while (end <= nums.size() && start <= end)
        {

            if (sum < s)
            {

                if (end<nums.size())
                {
                    sum += nums[end];
                }
                ++end;
            }
            else if (sum>=s)
            {
             
                if (minLen > end - start)
                {
                    minLen = end - start;
                }
                sum -= nums[start++];
            }

        }
        if (minLen == nums.size() + 1)
            return 0;
        else return minLen;

    }
};

int main()
{
    vector<int> nums{ 1, 2, 3, 4, 5 };
    Solution sol;
    auto temp = sol.minSubArrayLen(11, nums);

    return 0;
}

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int res = INT_MAX;
        if (nums[0] >= s) return 1;
        int lo = 0, hi = 1;
        int sum = nums[lo] + nums[hi];
        bool flag = false;
        while (hi < nums.size()){
            if (sum >= s){
                res = min(hi - lo + 1, res);
                sum = sum - nums[lo++];
                flag = true;
            }
            else if (hi + 1 < nums.size())
                sum = sum + nums[++hi];
            else
                break;
        }
        if (flag)
            return res;
        else
            return 0;
    }
};