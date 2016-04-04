#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<iterator>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (int i = 0; i < s.size(); ++i)
        {
            if ((s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= '0'&&s[i] <= '9'))
            {
                str.push_back(s[i]);
            }
            else if (s[i] >= 'A'&&s[i] <= 'Z')
            {
                str.push_back(s[i] + ('a' - 'A'));
            }

        }
        if (str.empty())
        {
            return true;
        }
        int l = 0, r = str.size() - 1;
        while (l <= r)
        {
            if (str[l] == str[r])
            {
                ++l;
                --r;
            }
            else
            {
                return false;
            }

        }

        return true;

    }
};


int main()
{
    string nums = "0aA";
    Solution sol;
    auto c = sol.isPalindrome(nums);

    return 0;
}
