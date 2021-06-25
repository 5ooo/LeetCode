class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0; 
        int strLen = s.length();  
        int preIdx = 0, postIdx = 0, rmIdx = 0;  
        bool exist[256] = { false }; 

        while(postIdx < strLen)
        {

            if(exist[s[postIdx]])
            {
                maxLen = max(maxLen, postIdx - preIdx);
                rmIdx = preIdx;

                while(s[preIdx++] != s[postIdx]);

                while(rmIdx != preIdx)
                {
                    if(exist[s[rmIdx]]) 
                        exist[s[rmIdx]] = false;
                    rmIdx++;
                }

                //postIdx = preIdx;
            }
            else
            {
                exist[s[postIdx]] = true;
                postIdx++;
            }
        }    

        return max(maxLen, postIdx - preIdx);
    }
};
