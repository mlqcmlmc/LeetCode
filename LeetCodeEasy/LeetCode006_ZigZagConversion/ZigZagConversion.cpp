#include<iostream>
#include<string>
#include<vector>
using namespace std;



class Solution {
public:
    string convert(string s, int numRows) {
    
        if (numRows <= 1 || s.length() < 3 || s.length() <= numRows) return s;

        vector<string> matrix;
        matrix.resize(numRows);
        int numBlock = s.size() / (2 * numRows - 2);
        if ((s.size() % (2 * numRows - 2)) != 0)
        {
            numBlock += 1;
        }
        int sIndex = 0;
        int rowIndex = 0;
        for (int i = 0; i < numBlock; ++i)
        {
            rowIndex = 0;
            for (; rowIndex < numRows&&sIndex<s.size(); ++rowIndex)
            {
                matrix[rowIndex].push_back(s[sIndex]);
                ++sIndex;
            }
            rowIndex = rowIndex - 2;
            for (; rowIndex > 0 && sIndex<s.size(); --rowIndex)
            {
                matrix[rowIndex].push_back(s[sIndex]);
                ++sIndex;
            }
        }
        string strline;
        for (int i = 0; i < numRows; ++i)
        {
            strline += matrix[i];
        }
        return strline;
    }

};


int main()
{
    string strRows = "A";
    int numRows = 1;
    Solution sol;
    string str = sol.convert(strRows, numRows);
    return 0;
}