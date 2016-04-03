//
//
//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//    bool search(vector<int>& nums, int target) {
//        int l = 0, r = nums.size() - 1;
//        return subSearch(nums, target, l, r);
//    }
//    bool subSearch(vector<int>& nums, int target, int l, int r)
//    {
//        int m = (r + l) / 2;
//        if (l>r)
//        {
//            return false;
//        }
//        if (nums[m] == target)
//        {
//            return true;
//        }
//        if (l == r)
//        {
//            return false;
//        }
//        bool rflag = false, lflag = false;
//        if ((nums[m] == nums[r] && m < r) || (nums[m] == nums[l] && m < l))
//        {
//            if (nums[m] == nums[r])
//            {
//                rflag = subSearch(nums, target, m+1, r);
//            }
//            if (nums[m] == nums[l])
//            {
//                lflag = subSearch(nums, target, l, m-1);
//            }
//            return rflag || lflag;
//        }
//        else if (nums[m]<target&&nums[r] >= target)
//        {
//            l = m + 1;
//        }
//        else if (nums[m]>target&&nums[l] <= target)
//        {
//            r = m - 1;
//        }
//        else if (nums[m]<nums[r])
//        {
//            l = m + 1;
//        }
//        else if (nums[m]>nums[l])
//        {
//            r = m - 1;
//        }
//        return subSearch(nums, target, l, r);
//
//    }
//};
//int main()
//{
//    vector<int> nums{ 3,1 };
//    Solution sol;
//    auto temp=sol.search(nums, 0);
//
//    return 0;
//}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return false;
        return search(nums, target, 0, nums.size() - 1);
        
    }

    bool search(vector<int>& nums, int target, int l, int r)
    {
        if (l > r)
            return false;

        int m = (l + r) / 2;
        int left = nums[l], right = nums[r], mid = nums[m];
        if (mid == target)
            return true;
            
        if (left < mid)
        {
            if (left <= target && target <= mid)
                return search(nums, target, l, m - 1);
            else
                return search(nums, target, m + 1, r);
        }
        else if (mid < right)
        {
            if (mid <= target && target <= right)
                return search(nums, target, m + 1, r);
            else
                return search(nums, target, l, m - 1);
        }
        else
        {
            return search(nums, target, l, m - 1) ||
                search(nums, target, m + 1, r);
        }
    }

};

int main()
{
    vector<int> nums{1, 3,1, 1 };
    Solution sol;
    auto temp=sol.search(nums, 1);

    return 0;
}
