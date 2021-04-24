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
    int climbStairs(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        
        int dp_i_2 = 1;
        int dp_i_1 = 2;
            
        int dp_i;
        
        for (int i = 3; i <= n; i++)
        {
            dp_i = dp_i_1 + dp_i_2;   
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        
        return dp_i;
    }
};


int main()
{
	Solution s;

	return 0;
}
