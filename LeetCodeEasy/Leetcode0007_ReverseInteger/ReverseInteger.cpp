#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 考虑溢出的情况，当溢出时，返回0，
//有时候用16进制表示最大值和最小值
//负数取余得到负数，负数取整也得到负数
class Solution {
public:
    int reverse(int x) {
        const int max = 0x7fffffff;  //int最大值  
        const int min = 0x80000000;  //int最小值  
        long long int sum = 0;
        while (x != 0)
        {
            int temp = x % 10;
            sum = sum * 10 + temp;
            if (sum > max || sum < min)   //溢出处理  
            {
                sum = sum > 0 ? max : min;
                return 0;
            }
            x = x / 10;
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    auto c = sol.reverse(-12345);

    return 0;
}