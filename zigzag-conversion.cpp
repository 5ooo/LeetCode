class Solution {
public:
    string convert(string s, int numRows) {
        vector<char> vChar;
        int strLen = s.length();
        int curRow = 0;
        int interval = 2 * (numRows - 1);

        if(interval == 0)
            return s;

        while(curRow < numRows)
        {
            for(int idx = 0; idx < strLen; idx++)
            {
                if((idx - curRow) % interval == 0 || (idx + curRow) % interval == 0)
                {
                    vChar.push_back(s[idx]);
                }
            }
            curRow++;
        }

        string res;
        for(int i = 0; i < vChar.size(); i++)
        {
            res += vChar[i];
        }

        return res;

    }
};
