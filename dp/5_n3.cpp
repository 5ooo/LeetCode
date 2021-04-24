#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <utility>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        string ret;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (i - j <= ret.size())
                    break;

                string tmp = s.substr(j, i - j);
                if (is_palindromic(tmp))
                {
                    ret = tmp;
                    break;
                }
            }
        }

        return ret;
    }
    
    bool is_palindromic(string s)
    {   
        int i = 0; 
        for (; i < s.size() / 2; i++)
        {   
            if (s[i] != s[s.size() - 1 - i])
                break;
        }   
        
        return (i == s.size() / 2) ? true : false;
    }
};

int main()
{
	Solution s;

    string input = "azwdzwmwcqzgcobeeiphemqbjtxzwkhiqpbrprocbppbxrnsxnwgikiaqutwpftbiinlnpyqstkiqzbggcsdzzjbrkfmhgtnbujzszxsycmvipjtktpebaafycngqasbbhxaeawwmkjcziybxowkaibqnndcjbsoehtamhspnidjylyisiaewmypfyiqtwlmejkpzlieolfdjnxntonnzfgcqlcfpoxcwqctalwrgwhvqvtrpwemxhirpgizjffqgntsmvzldpjfijdncexbwtxnmbnoykxshkqbounzrewkpqjxocvaufnhunsmsazgibxedtopnccriwcfzeomsrrangufkjfzipkmwfbmkarnyyrgdsooosgqlkzvorrrsaveuoxjeajvbdpgxlcrtqomliphnlehgrzgwujogxteyulphhuhwyoyvcxqatfkboahfqhjgujcaapoyqtsdqfwnijlkknuralezqmcryvkankszmzpgqutojoyzsnyfwsyeqqzrlhzbc";

	printf("%s\n", s.longestPalindrome(input).c_str());

	return 0;
}
