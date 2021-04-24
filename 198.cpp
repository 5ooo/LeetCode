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
    int rob(vector<int>& nums) {
        int dp_i = 0;   //第i间房子最多能抢的钱
        int dp_i_1 = 0; //第i+1间房子最多能抢的钱
        int dp_i_2 = 0; //第i+2间房子最多能抢的钱
        
        //从最后一间房子开始，往前移动
        for (int i = nums.size() - 1; i >= 0; i--) {
            dp_i = max(dp_i_1, nums[i] + dp_i_2);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        
        return dp_i;
    }
};

int main()
{
        vector<int> test;
	test.push_back(2);
	test.push_back(7);
	test.push_back(9);
	test.push_back(3);
	test.push_back(1);

	Solution s;

	printf("%d\n", s.rob(test));

	return 0;
}
