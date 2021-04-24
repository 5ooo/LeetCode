#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <utility>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.length() == 0)
            if (isMatchEmptyStr(p))
                return true;
            else
                return false;

        bool match;
        if (s[0] == p[0] || p[0] == '.')
            match = true;
        else
            match = false;

        if (p.length() >= 2 && p[1] == '*')
            return  isMatch(s, p.substr(2)) ||
                    (match && isMatch(s.substr(1), p)); 
        else 
            return match && isMatch(s.substr(1), p.substr(1));
    } 
    
    bool isMatchEmptyStr(string s)
    {
        stack<char> buf;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '*')
                if (buf.size() == 0)
                    buf.push(s[i]);
                else
                    return false;
            else
                if (buf.size() == 1)
                    buf.pop();
                else
                    return false;
        }
        
        return buf.empty();
    }

};


int main()
{
	Solution s;

	return 0;
}
