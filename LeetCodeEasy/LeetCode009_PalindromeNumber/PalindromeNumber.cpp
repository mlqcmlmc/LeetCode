#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//改题所有负数都输出false，只有整数才可以
class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long long int sum = 0;
        while (temp)
        {
            sum = sum * 10 + temp % 10;
            temp = temp / 10;
        }
        if (x == sum&&x >= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution sol;
    auto c = sol.isPalindrome(1234321);

    return 0;
}