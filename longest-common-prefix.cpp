class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string res;
        int minLen;
            
        if(strs.size() == 0)
            return "";
        else
            minLen = strs[0].length();
            
        for(int i = 1; i < strs.size(); i++)
        {
            if(minLen > strs[i].length())
                minLen = strs[i].length();
        }

        for(int i = 0; i < minLen; i++)
        {
            int j = 0;
            for(; j < strs.size() - 1; j++)
            {
                if(strs[j][i] != strs[j + 1][i])
                {
                    break;
                }
            }

            if(j == strs.size() - 1)
                res += strs[j][i];
            else
                break;
        }

        return res;
    }
};
