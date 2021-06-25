class Solution {
public:
    string intToRoman(int num) {
        string res;
        int tmp;

        int n[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string r[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        for(int i = 0; i < 13; i++)
        {
            tmp = num / n[i];

            for(; tmp > 0; tmp--)
            {
                res += r[i];
            }

            num %= n[i];
        }

        return res;
    }
};
