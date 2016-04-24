
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        int maxSubstr = 0;
//        unordered_map<char, int> cindex;
//        int begin = 0;
//        for (int i = 0; i < s.size(); ++i)
//        {
//            auto strPos = s.find(s[i], begin);//��begin��ʼ��
//            if (strPos == i)
//            {
//                cindex[s[i]] = i;
//            }
//            else 
//            {
//                if (maxSubstr < i - begin)
//                {
//                    maxSubstr = i - begin;
//                }
//                begin = cindex[s[i]] + 1;
//                cindex[s[i]] = i;
//            }
//        }
//        if (maxSubstr < s.size() - begin)
//        {
//            maxSubstr = s.size() - begin;
//        }
//
//        return maxSubstr;
//    }
//};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cindex(256, -1);
        int maxSubstr = 0;
        int begin = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            if (cindex[s[i]] > begin)
            {
                begin = cindex[s[i]];
            }
            if (maxSubstr < i - begin)
            {
                maxSubstr = i - begin;
            }
            cindex[s[i]] = i;
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
