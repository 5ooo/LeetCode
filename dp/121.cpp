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
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int ret = 0;
        
        for (int i = 0; i < prices.size(); i++)
        {   
            buy = min(buy, prices[i]);
            ret = max(ret, prices[i] - buy);
        }   
        
        return ret;
    }
};


int main()
{
	Solution s;

	return 0;
}
