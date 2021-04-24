#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <utility>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isValid(string s) {
        //pair<char, char> smlBracket('(', ')');
        //pair<char, char> midBracket('[', ']');
        //pair<char, char> bigBracket('{', '}');

		if (s.length() % 2 != 0)
			return false;

		map<char, char> brackets;
		brackets['('] = ')';
		brackets['['] = ']';
		brackets['{'] = '}';

		stack<char> _stack;
		for (int i = 0; i < s.length(); i++)
        {
            if (brackets.find(s.at(i)) != brackets.end())
			    _stack.push(s.at(i));
            else
            {
                if (_stack.size() == 0)
                    return false;

                if (s.at(i) != brackets[_stack.top()])
                    return false;

                _stack.pop();
            }
		}

        if (_stack.size() == 0)
            return true;
        else
            return false;
    }
};


int main()
{
	Solution s;

	printf("%d\n", (int)s.isValid("(([{}]))"));
	printf("%d\n", (int)s.isValid("()[]{}"));
	printf("%d\n", (int)s.isValid("){"));

	return 0;
}
