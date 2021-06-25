class Solution {
public:
    bool isValid(string s) {
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
