#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//�������и��������false��ֻ�������ſ���
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