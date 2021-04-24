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
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
            return nums.size();

        if (nums.size() == 2)
            return nums[1] > nums[0] ? 2 : 1;

        vector<int> dp(nums.size(), 1);

        dp[1] = nums[1] > nums[0] ? 2 : 1; 

        for (int i = 2; i < nums.size(); i++)
        {
            int j = i - 1;
            while (j >= 0)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[i] < dp[j] + 1)
                        dp[i] = dp[j] + 1;
                }

                j--;
            }
        }

        int ret = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (ret < dp[i])
                ret = dp[i];
        }

        return ret;
    }

};


int main()
{
	Solution s;

	return 0;
}
