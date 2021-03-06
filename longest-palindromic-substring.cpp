class Solution {
public:
    string longestPalindrome(string s) {
        string ret;

        if (s.length() >= 1)
            ret = s[0];
        else
            return s;

        int left, right;

        for (int i = 0; i < s.length(); i++)
        {
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.length())
            {
                if (s[left] == s[right])
                {
                    if (ret.length() < right - left + 1)
                        ret = s.substr(left,  right - left + 1);
                }
                else
                    break;

                left--;
                right++;
            }

            left = i - 1;
            right = i + 1;
            while (left >= 0 && right < s.length())
            {
                if (s[left] == s[right])
                {
                    if (ret.length() < right - left + 1)
                        ret = s.substr(left,  right - left + 1);
                }
                else
                    break;

                left--;
                right++;
            }
        }

        return ret;
    }
};
