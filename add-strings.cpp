class Solution {
public:
    string addStrings(string num1, string num2) {
        stack<int> s;
        
        int sum;
        int k = 0;
        int in = 0;
        int max_len = max(num1.length(), num2.length());
        for (int i = 1; i <= max_len; i++)
        {
            if (num1.length() >= i && num2.length() >= i)
            {
                sum = in + num1[num1.length() - i] + num2[num2.length() - i] - 2 * '0';
                k = sum % 10;
                in = sum / 10;  
            }
            else if (num1.length() >= i && num2.length() < i)
            {
                sum = in + num1[num1.length() - i] - '0';
                k = sum % 10;
                in = sum / 10;
            }
            else if (num1.length() < i && num2.length() >= i)
            {
                sum = in + num2[num2.length() - i] - '0';
                k = sum % 10;
                in = sum / 10;
            }
            else
                break;
            
            s.push(k);
        }
        
        string ret;
        if (in != 0)
            ret = "1";
        
        while (s.size() != 0)
        {
            ret = ret + (char)(s.top()+'0');
            s.pop();
        }
        
        return ret;
    }
};
