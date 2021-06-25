class Solution {
public:
    int romanToInt(string s) {
        int res = 0;

        int n[7] = {1000, 500, 100, 50, 10, 5, 1};
        char r[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};

        for(int i = 0; i < s.length(); i++)
        {
            for(int j = 0; j < 7; j++)
            {
                if(s[i] == r[j])
                {
                    int k = 0;

                    if(i + 1 < s.length())
                        while(s[i + 1] != r[k])
                            k++;

                    if(i + 1 < s.length() && n[j] < n[k])
                        res -= n[j];
                    else
                        res += n[j];
                }
            }
        }

        return res;
    }
};
