#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// �������������������ʱ������0��
//��ʱ����16���Ʊ�ʾ���ֵ����Сֵ
//����ȡ��õ�����������ȡ��Ҳ�õ�����
class Solution {
public:
    int reverse(int x) {
        const int max = 0x7fffffff;  //int���ֵ  
        const int min = 0x80000000;  //int��Сֵ  
        long long int sum = 0;
        while (x != 0)
        {
            int temp = x % 10;
            sum = sum * 10 + temp;
            if (sum > max || sum < min)   //�������  
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