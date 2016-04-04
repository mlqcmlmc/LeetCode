#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<iterator>
using namespace std;
////注意要区别字符串的不同
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> vstr;
        int pos = 0;
        while (!str.empty())
        {
            pos = str.find(' ');
            if (pos != string::npos)
            {
                vstr.push_back(str.substr(0, pos));
                str.erase(0, pos + 1);
            }
            else
            {
                vstr.push_back(str);
                str.erase(0);
            }

        }
        if (pattern.size() != vstr.size())
        {
            return false;
        }
        for (int i = 0; i < pattern.size(); ++i)
        {
            auto ppos = pattern.find(pattern[i]);
            if (ppos<i)
            {
                if (vstr[i] != vstr[ppos])
                {
                    return false;
                }
            }
            else
            {
                auto vstrite = find(vstr.begin(), vstr.end(), vstr[i]);
                if (vstrite!=vstr.begin()+i)
                {
                    return false;
                }

            }
        }

        return true;

    }
};


int main()
{
    string spattern = "abba",sstr = "dog dog dog dog";
    Solution sol;
    auto c = sol.wordPattern(spattern,sstr);

    return 0;
}
