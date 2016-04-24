
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string preS = preString(s);
        int maxBorder = 0, id = 0;
        vector<int> p(preS.size(), 0);
        for (int i = 1; i<preS.size(); ++i)
        {
            if (maxBorder>i)
            {
                p[i] = min(p[2 * id - i], maxBorder - i);
            }
            else
            {
                p[i] = 1;
            }
            while (preS[i + p[i]] == preS[i - p[i]])
            {
                ++p[i];
            }
            if (i + p[i] > maxBorder)
            {
                maxBorder = p[i] + i;
                id = i;
            }
        }
        int maxSubNum = 0, maxIndex = 0;
        for (int i = 0; i<p.size(); ++i)
        {
            if (p[i]>maxSubNum)
            {
                maxSubNum = p[i];
                maxIndex = i;
            }
        }
        string maxSubStr = preS.substr(maxIndex + 1 - maxSubNum, 2 * maxSubNum - 1);
        string outStr;
        for (int i = 0; i < maxSubStr.size(); ++i)
        {
            if (maxSubStr[i] != '#')
            {
                outStr.push_back(maxSubStr[i]);
            }
        }
        return outStr;
    }
    string preString(string s)
    {
        string preS;
        preS.push_back('$');
        preS.push_back('#');
        for (int i = 0; i < s.size(); ++i)
        {
            preS.push_back(s[i]);
            preS.push_back('#');
        }
        preS.push_back('%');
        return preS;

    }
};

int main()
{
    string str = "a";
    Solution sol;
    auto temp = sol.longestPalindrome(str);

    return 0;
}
