
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std; 

//class Solution {
//public:
//    void reverseWords(string &s) {
//        int left = 0;
//        while (left < s.size() && s[left] == ' ')
//        {
//            s.erase(left, 1);
//        }
//        int right = s.size() - 1;
//        while (right >= 0 && s[right] == ' ')
//        {
//            --right;
//            
//        }
//        if (right<s.size() - 1)
//        {
//            s.erase(right + 1);
//
//        }
//        reverseString(s, 0, s.size() - 1);
//        left = 0;
//        right = 0;
//        while (true)
//        {
//           /* while (left < s.size() && s[left] == ' ')
//            {
//                s.erase(left, 1);
//            }*/
//            right = left;
//            if (right >= s.size())
//            {
//                break;
//            }
//            while (right < s.size() && s[right] != ' ')
//            {
//                ++right;
//            }
//            reverseString(s, left, right - 1);
//            left = right + 1;
//        }
//    }
//    void reverseString(string &s, int left, int right)
//    {
//        char temp;
//        while (right < s.size() && left < right)
//        {
//            temp = s[left];
//            s[left] = s[right];
//            s[right] = temp;
//            left++;
//            right--;
//        }
//    }
//};

//
//class Solution {
//public:
//
//    // function to reverse any part of string from i to j (just one word or entire string)
//    void reverseword(string &s, int i, int j){
//        while (i < j){
//            char t = s[i];
//            s[i++] = s[j];
//            s[j--] = t;
//        }
//    }
//
//    void reverseWords(string &s) {
//
//        int i = 0, j = 0;
//        int l = 0;
//        int len = s.length();
//        int wordcount = 0;
//
//        while (true){
//            while (i < len && s[i] == ' ') i++;  // skip spaces in front of the word
//            if (i == len) break;
//            if (wordcount) s[j++] = ' ';
//            l = j;
//            while (i < len && s[i] != ' ') { s[j] = s[i]; j++; i++; }
//            reverseword(s, l, j - 1);                // reverse word in place
//            wordcount++;
//
//        }
//
//        s.resize(j);                           // resize result string
//        reverseword(s, 0, j - 1);                  // reverse whole string
//    }
//};



class Solution {
public:

    void reverseword(string &s, int i, int j){
        while (i<j)
        {
            int temp = s[i]; 
            s[i++] = s[j];
            s[j--] = temp;
        }
    }

    void reverseWords(string &s) {
        int left = 0, right = 0;
        int inx = -1;
        int len = s.size();
        int countWord = 0;
        while (true)
        {
            while (left<len&&s[left]==' ')
            {
                ++left;
            }
            if (left==len)
            {
                break;
            }
            right = left;
            while (right<len&&s[right] != ' ')
            {
                ++right;
            }
            reverseword(s, left, right - 1);
            for (int i = 0; i < right - left;++i)
            {
                ++inx;
                s[inx] = s[left + i];
            }
            s[++inx] = ' ';   
            left = right;
        }
        if (inx==-1)
        {
            s.clear();
            return ;
        }
        else
        {
            s.resize(inx);
            reverseword(s, 0, inx - 1);
        }
        

    }
};

int main()
{
    string str = "   a   ";
    Solution sol;
    sol.reverseWords(str);

    return 0;
}