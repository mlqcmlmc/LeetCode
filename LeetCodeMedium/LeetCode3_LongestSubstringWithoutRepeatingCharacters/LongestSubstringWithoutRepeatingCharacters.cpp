
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSubstr = 0;
        unordered_map<char, int> cindex;
        int begin = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            auto strPos = s.find(s[i], begin);//´Óbegin¿ªÊ¼ÕÒ
            if (strPos == i)
            {
                cindex[s[i]] = i;
            }
            else 
            {
                if (maxSubstr < i - begin)
                {
                    maxSubstr = i - begin;
                }
                begin = cindex[s[i]] + 1;
                cindex[s[i]] = i;
            }
        }
        if (maxSubstr < s.size() - begin)
        {
            maxSubstr = s.size() - begin;
        }

        return maxSubstr;
    }
};

int main()
{
    string str = "qwnfenpglqdq";
    Solution sol;
    auto temp = sol.lengthOfLongestSubstring(str);

    return 0;
}
