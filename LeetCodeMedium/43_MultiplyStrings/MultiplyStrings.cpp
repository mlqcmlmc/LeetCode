#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty())
            return string();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string multiplyNum(num1.size() + num2.size()+1, '0');
        for (int i = 0; i < num2.size(); ++i)
        {
            for (int j = 0; j < num1.size();++j)
            {
                int temp = (num1[j] - '0')*(num2[i] - '0');
                multiplyNum[i + j + 1] = (multiplyNum[i + j + 1] - '0' + (multiplyNum[i + j] - '0' + temp) / 10) + '0';
                multiplyNum[i + j] = (multiplyNum[i + j] - '0' + temp) % 10 + '0';
            }
        }
        reverse(multiplyNum.begin(), multiplyNum.end());
        auto pos = multiplyNum.find_first_not_of('0');
        if (pos==string::npos)
        {
            return "0";
        }
        else
        {
            return multiplyNum.substr(pos);
        }      
    }
};

int main()
{
    Solution sol;
    string a = sol.multiply("12", "34");

    return 0;
}