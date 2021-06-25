class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length() == 0 && needle.length() == 0)
            return 0;
        
        if (haystack.length() < needle.length())
            return -1;
        
        for (int i = 0; i <= haystack.length() - needle.length(); i++)
        {
            int j = 0;
            for (int k = i; j < needle.length(); j++, k++)
            {
                if (haystack[k] != needle[j])
                    break;
            }

            if (j == needle.length())
                return i;
        }   

        return -1; 
    }   
};
