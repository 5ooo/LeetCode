class Solution {
public:
    int reverse(int x) {
        long res = 0;

        while(x != 0)
        {
            res = res * 10 + x % 10;
            x /= 10;
        }

        if((long)((int)res) == res)
            return (int)res;
        else
            return 0;
    }
};
