#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <utility>
#include <string.h>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.length() == 0 || text2.length() == 0)
            return 0;

        int dp[text1.length() + 1][text2.length() + 1];
        for (int i = 0; i <= text1.length(); i++)
            dp[i][0] = 0;

        for (int j = 0; j <= text2.length(); j++)
            dp[0][j] = 0;

        for (int i = 1; i <= text1.length(); i++)
        {   
            for (int j = 1; j <= text2.length(); j++)
            {   
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i -1][j], dp[i][j - 1]);
            }   
        }   
            
        return dp[text1.length()][text2.length()]; 
    }
};


int main()
{
	Solution s;

	printf("%d\n", s.longestCommonSubsequence("ezupkr", "ubmrapg"));

	return 0;
}
