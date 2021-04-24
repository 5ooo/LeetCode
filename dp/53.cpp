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
    int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;

    	int sum = 0;
		int maxSum = nums[0];
	
		for (int i = 0; i < nums.size(); i++)
		{
			if (sum < 0)
				sum = 0;

			sum += nums[i];
			if (maxSum < sum)
				maxSum = sum;
		}

		return maxSum;
    }
};


int main()
{
	Solution s;

	return 0;
}
