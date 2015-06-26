#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
using namespace std;


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> res;
        if (nums.empty())                   //当没有数字时，直接返回空串
        {
            return res;
        }

        int index_begin = 0;
        int index_end = 0;
        int count = 1;
        for (; index_end < nums.size(); ++index_end)
        {
            if (index_end == nums.size() - 1)
            {
                if (index_end == index_begin)
                {
                    res.push_back(to_string(nums[index_begin]));
                }
                else
                {
                    res.push_back(to_string(nums[index_begin]) + "->" + to_string(nums[index_end]));
                }
            }
            else if (nums[index_end+1] == nums[index_begin] + count)
            {
                ++count;
            }
            else
            {
                if (index_end == index_begin)
                {
                    res.push_back(to_string(nums[index_begin]));
                }
                else
                {
                    res.push_back(to_string(nums[index_begin]) + "->" + to_string(nums[index_end]));
                }
                index_begin = index_end+1;
                count = 1;
            }
        }
        return res;
    }
};

int main()
{
    int a[] = { 0, 1, 2, 4, 5, 7 };
    vector<int> nums;
    copy(begin(a), end(a), back_inserter(nums));
    Solution sol;
    auto c = sol.summaryRanges(nums);

    return 0;
}