class Solution {
public:
    int myAtoi(string str) {
        const int MAX = 2147483647;
        const int MIN = -2147483648;
        long res = 0;  
        int idx = 0;
        int last = 0;
        bool posivite = 0;
        int strLen = str.length();

        int bitmap[256] = {0};
        for(int i = 0; i < 10; i++)
        {
            bitmap[i + '0'] = 1;
        }
        bitmap['+'] = 2;
        bitmap['-'] = 2;
        bitmap[' '] = 2;

        if(strLen == 0 || !bitmap[str[0]])
            return 0;

        for(; str[idx] == ' '; idx++);

        if(str[idx] == '+')
        {
            idx++;
        }
        else if(str[idx] == '-')
        {
            idx++;
            posivite = 1;
        }

        while(idx < strLen)
        {
            if(bitmap[str[idx]] != 1)
                break;

            if(posivite)
            {
                res = res * 10 + str[idx] - '0';
                if(-res < MIN)
                    return MIN;
            }
            else
            {
                res = res * 10 + str[idx] - '0';
                if(res > MAX)
                { 
                    return MAX;
                }
            }

            idx++;         
        }

        return posivite ? -res : res;              
    }
};
